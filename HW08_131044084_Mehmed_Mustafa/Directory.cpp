#include "Directory.h"
#include "Executable.h"
#include "TextFile.h"
#include <iostream>
#include <iomanip> // setw
#include <set>
using std::set;
using std::cout;
using std::cerr;
using std::endl;
using std::setw;
using std::left;
using std::right;
using namespace std;

namespace GTU_Mehmed{
    
    // Function to order File* in set
    bool compFunc::operator()(File* a, File* b){
        //If File* a is a Directory
        //and File* b isn't a Direcory
        //then a must precede b
        if(NULL != dynamic_cast<Directory*>(a) &&
            NULL == dynamic_cast<Directory*>(b))
        {
            return true; // a precede b
        }
        //If File* b is a Directory
        //and File* a isn't a Direcory
        //then b must precede a
        if(NULL == dynamic_cast<Directory*>(a) &&
            NULL != dynamic_cast<Directory*>(b))
        {
            return false; // b precede a
        }

        // If both File* are Directory or aren't Directory
        if(a->getName() < b->getName())
            return true; // a precede b
        else // (a->getName() >= b->getName())
            return false; // b precede a
    }
    
    // Constructors
    Directory::Directory():File(){
        // Default constructor
    }
    Directory::Directory(string valName):File(valName){
        // Constructor that takes only name
    }
    Directory::Directory(string valName, string valOwner)
              :File(valName, valOwner){
        // Constructor that takes name and owner
    }
    Directory::Directory(string valName, string valOwner, int valSize)
              :File(valName, valOwner, valSize){
        // Constructor that takes name, owner and size
    }
    Directory::Directory(string valName, string valOwner, int valSize, 
        string valLastMod):File(valName, valOwner, valSize, valLastMod){
        // Constructor that takes name, owner, size and last modification
    }
    
    // Destructor
    Directory::~Directory(){
        for(set<File*>::iterator it = files.begin(); it != files.end(); ++it )
        {
            // Free the allocated memory
            delete *it;
        }
    }
    
    
    // cp function copies currentFile referanse to the Directory object
    // Deep copy
    bool Directory::cp(const File& currentFile){
        
	if(NULL == dynamic_cast<const Directory*> (&currentFile))
	{ // The parameter File object isn't a Directory object 
            if(NULL == dynamic_cast<const Executable*> (&currentFile))
            { // The File object is a TextFile object, since it isn't an Executable
                
                // Converts the File referance to TextFile pointer
                // Since we know that coming currentFile is TextFile object
                const TextFile* textTemp = dynamic_cast<const TextFile*> (&currentFile);
                
                // Creates new fresh copy from the textFile pointer
                // Deep copy
                TextFile* freshCopy = new TextFile(*textTemp);
                
                // Creates path for the newly created freshCopy
                string newPath = currentFile.path() + "/" + getName();
                
                // Set the new path to the created freshCopy
                freshCopy->setPath(newPath);
                
                // Check if insertion is successful
                if(true == files.insert(freshCopy).second)
                {// This object is not in the directory
                    return true;
                }
                else // The object is in the directory
                { // currentFile object is already the directory
                    //So the object isn't copied to the directory
                    cout << currentFile.getName() << " cannot be copied!" << endl;
                    cout << currentFile.getName() << " is already in the directory!"<< endl;
                    return false;
                }
            }
            else // The File object is an Executable object
            {
                // Converts the File referance to Executable pointer
                // Since we know that coming currentFile is Executable object
                const Executable* exeTemp = dynamic_cast<const Executable*> (&currentFile);
                
                // Creates new fresh copy from the Executable pointer
                // Deep copy                
                Executable* freshCopy = new Executable(*exeTemp);
                
                // Creates path for the newly created freshCopy
                string newPath = currentFile.path() + "/" + getName();
                
                // Set the new path to the created freshCopy
                freshCopy->setPath(newPath);
                
                // Check if insertion is successful
                if(true == files.insert(freshCopy).second)
                {// This object is not in the directory
                    return true;
                }
                else // The insertion is unsuccessful
                { // currentFile object is already the directory
                    //So the object isn't copied to the directory
                    cout << currentFile.getName() << " cannot be copied!" << endl;
                    cout << currentFile.getName() << " is already in the directory!"<< endl;
                    return false;
                }
            }
    }
    else // The File object is a Directory object
    {
        // Converts the File referance to Directory pointer
        // Since we know that coming currentFile is Directory object
        const Directory* dirTemp = dynamic_cast<const Directory*> (&currentFile);
        
        // Creates new fresh copy from the Directory pointer
        // Deep copy 
        Directory* freshCopy = new Directory(*dirTemp);
        
        // Creates path for the newly created freshCopy
        string newPath = currentFile.path() + "/" + getName();
            
        // Set the new path to the created freshCopy
        freshCopy->setPath(newPath);
        
        // Check if insertion is successful
        if(true == files.insert(freshCopy).second)
        {// currentFile object is not in the directory
            // So the object is copied to the directory
            return true;
        }
        else // The insertion is unsuccessfuvl
        { // currentFile object is already the directory
            //So the object isn't copied to the directory
            cout << currentFile.getName() << " cannot be copied!" << endl;
            cout << currentFile.getName() << " is already in the directory!"<< endl;
            return false;
        }                    
    }
    }
    
    // Prints the directory according to string parameter
    // Maximum lenght that can be passed as a parameter is 3
    void Directory::ls(string valCommand)const{
        int lenght = valCommand.length();
        
    switch(lenght)
    {
        case 0: // ls("")
            // Print every visible file in the directory as a list
            for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
            {
                // If the file is hidden, skip it's name
                // Check first character of the name
                if(((*it)->getName()).at(0) == '.')
                    continue;

                cout << left;
                cout << setw(5) << (*it)->getName();
            }
            cout << endl;
            break;
        case 1: // ls("a") or ls("l") or ls("R")
            if(valCommand == "a") // ls("a")
            {
                // Print every file(hidden files too) in the directory as a list
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    cout << left;
                    cout << setw(5) << (*it)->getName();
                }
                cout << endl;
            }
            else if(valCommand == "l") // ls("l")
            {
                // Print first info line
                cout << left;
                cout << setw(15) << "FILE NAME";
                cout << setw(10) << "OWNER";
                cout << right;
                cout << setw(7)  << "SIZE(KB)";
                cout << setw(14) << "LAST MOD";
                cout << right;
                cout << setw(20) << "COMPILER/TEXT TYPE";
                cout << endl; 
                
                // Print every visible file in the directory as a list
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    // If the file is hidden, skip it's name
                    // Check first character of the name
                    if(((*it)->getName()).at(0) == '.')
                        continue;
                    
                    // Print the File's information that is pointed by it
                    cout << left;
                    cout << setw(15) << (*it)->getName();
                    cout << setw(10) << (*it)->getOwner();
                    cout << right;
                    cout << setw(7)  << (*it)->getSize();
                    cout << setw(15) << (*it)->getLastMod();

                    // If the object is Executable, print CompilerName
                    if(NULL != dynamic_cast<const Executable*>(*it))
                    {
                        // Make cast to be able to use getCompiler()
                        const Executable* exeTemp = dynamic_cast<const Executable*> (*it);
                        cout << right;
                        cout << setw(20) << exeTemp->getCompiler(); // Print compiler
                    }

                    // If the object is TextFile, print TextType
                    if(NULL != dynamic_cast<const TextFile*>(*it))
                    {
                        // Make cast to be able to use getTextType()
                        const TextFile* textTemp = dynamic_cast<const TextFile*> (*it);
                        cout << right;
                        cout << setw(20) << textTemp->getTextType(); // Print text type
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else if(valCommand == "R") // ls("R")
            {
                // Print directory path
                cout << path() + "/" + getName() << ":" << endl;
                
                // Print every visible file in the directory as a list Recursively
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    // If the file is hidden, skip it's name
                    // Check first character of the name
                    if(((*it)->getName()).at(0) == '.')
                        continue;

                    cout << left;
                    cout << setw(5) << (*it)->getName();
                }
                cout << endl << endl;
                
                // Check the Directory and recal itself if a Directory object is found
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    if(NULL != dynamic_cast<const Directory*>(*it))
                    {// Directory is found
                        // If the file is hidden, skip it's name
                        // Check first character of the name
                        if(((*it)->getName()).at(0) == '.')
                            continue;
                        
                        // Recall itself
                        (*it)->ls("R");
                    }
                }   
            }
            else
                cout << "Wrong one lenght parameter in ls function" << endl;

            break;
        case 2: // All two combinations made with a, R and l, for ex. ("al")
            if(valCommand == "al" || valCommand == "la")
            {
                // Print first info line
                cout << left;
                cout << setw(15) << "FILE NAME";
                cout << setw(10) << "OWNER";
                cout << right;
                cout << setw(7)  << "SIZE(KB)";
                cout << setw(14) << "LAST MOD";
                cout << right;
                cout << setw(20) << "COMPILER/TEXT TYPE";
                cout << endl;
                
                // Print every file(hidden files too) in the directory
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    // Print the File's information that is pointed by it
                    cout << left;
                    cout << setw(15) << (*it)->getName();
                    cout << setw(10) << (*it)->getOwner();
                    cout << right;
                    cout << setw(7)  << (*it)->getSize();
                    cout << setw(15) << (*it)->getLastMod();

                    // If the object is Executable, print CompilerName
                    if(NULL != dynamic_cast<const Executable*>(*it))
                    {
                        // Make cast to be able to use getCompiler()
                        const Executable* exeTemp = dynamic_cast<const Executable*> (*it);
                        cout << right;
                        cout << setw(20) << exeTemp->getCompiler(); // Print compiler
                    }

                    // If the object is TextFile, print TextType
                    if(NULL != dynamic_cast<const TextFile*>(*it))
                    {
                        // Make cast to be able to use getTextType()
                        const TextFile* textTemp = dynamic_cast<const TextFile*> (*it);
                        cout << right;
                        cout << setw(20) << textTemp->getTextType(); // Print text type
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else if(valCommand == "aR" || valCommand == "Ra")
            {
                // Print directory path
                cout << path() + "/" + getName() << ":" << endl;
                
                // Print every file(hidden files too) in the directory Recursively
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    cout << left;
                    cout << setw(5) << (*it)->getName();
                }
                cout << endl << endl;
                
                // Check the Directory and recal itself if a Directory object is found
                // Hidden files too
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    if(NULL != dynamic_cast<const Directory*>(*it))
                    {// Directory is found
                        // Recall itself
                        (*it)->ls("aR");
                    }
                }   
            }
            else if(valCommand == "Rl" || valCommand == "lR")
            {
                // Print directory path
                cout << path() + "/" + getName() << ":" << endl;

                // Print first info line
                cout << left;
                cout << setw(15) << "FILE NAME";
                cout << setw(10) << "OWNER";
                cout << right;
                cout << setw(7)  << "SIZE(KB)";
                cout << setw(14) << "LAST MOD";
                cout << right;
                cout << setw(20) << "COMPILER/TEXT TYPE";
                cout << endl;

                // Print every visible file in the directory Recursively
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    // If the file is hidden, skip it's name
                    // Check first character of the name
                    if(((*it)->getName()).at(0) == '.')
                        continue;
                    
                    // Print the File's information that is pointed by it
                    cout << left;
                    cout << setw(15) << (*it)->getName();
                    cout << setw(10) << (*it)->getOwner();
                    cout << right;
                    cout << setw(7)  << (*it)->getSize();
                    cout << setw(15) << (*it)->getLastMod();

                    // If the object is Executable, print CompilerName
                    if(NULL != dynamic_cast<const Executable*>(*it))
                    {
                        // Make cast to be able to use getCompiler()
                        const Executable* exeTemp = dynamic_cast<const Executable*> (*it);
                        cout << right;
                        cout << setw(20) << exeTemp->getCompiler(); // Print compiler
                    }

                    // If the object is TextFile, print TextType
                    if(NULL != dynamic_cast<const TextFile*>(*it))
                    {
                        // Make cast to be able to use getTextType()
                        const TextFile* textTemp = dynamic_cast<const TextFile*> (*it);
                        cout << right;
                        cout << setw(20) << textTemp->getTextType(); // Print text type
                    }

                    cout << endl;
                }
                cout << endl;

                // Check the Directory and recal itself if a Directory object is found
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    if(NULL != dynamic_cast<const Directory*>(*it))
                    { // Directory is found
                        // If the file is hidden, skip it's name
                        // Check first character of the name
                        if(((*it)->getName()).at(0) == '.')
                            continue;
                        // Recall itself
                        (*it)->ls("Rl");
                    }
                }
            }
            else
                cout << "Wrong two lenght parameter in ls function" << endl;

            break;
        case 3: // All three combinations made with a, R and l, for ex. ("Rla")
            if(valCommand == "alR" || valCommand == "aRl" ||
               valCommand == "laR" || valCommand == "lRa" ||
               valCommand == "Ral" || valCommand == "Rla")
            {
                // Print directory path
                cout << path() + "/" + getName() << ":" << endl;

                // Print first info line
                cout << left;
                cout << setw(15) << "FILE NAME";
                cout << setw(10) << "OWNER";
                cout << right;
                cout << setw(7)  << "SIZE(KB)";
                cout << setw(14) << "LAST MOD";
                cout << right;
                cout << setw(20) << "COMPILER/TEXT TYPE";
                cout << endl;

                // Print every file(hidden files too) in the directory Recursively
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    // Print the File's information that is pointed by it
                    cout << left;
                    cout << setw(15) << (*it)->getName();
                    cout << setw(10) << (*it)->getOwner();
                    cout << right;
                    cout << setw(7)  << (*it)->getSize();
                    cout << setw(15) << (*it)->getLastMod();

                    // If the object is Executable, print CompilerName
                    if(NULL != dynamic_cast<const Executable*>(*it))
                    {
                        // Make cast to be able to use getCompiler()
                        const Executable* exeTemp = dynamic_cast<const Executable*> (*it);
                        cout << right;
                        cout << setw(20) << exeTemp->getCompiler(); // Print compiler
                    }

                    // If the object is TextFile, print TextType
                    if(NULL != dynamic_cast<const TextFile*>(*it))
                    {
                        // Make cast to be able to use getTextType()
                        const TextFile* textTemp = dynamic_cast<const TextFile*> (*it);
                        cout << right;
                        cout << setw(20) << textTemp->getTextType(); // Print text type
                    }

                    cout << endl;
                }
                cout << endl;

                // Check the Directory and recal itself if a Directory object is found
                for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
                {
                    if(NULL != dynamic_cast<const Directory*>(*it))
                    { // Directory is found
                        // Recall itself
                        (*it)->ls("alR");
                    }
                }
            }
            else
                cout << "Wrong three lenght parameter in ls function" << endl;
            
            break;
        default:
            cout << "Wrong parameters in ls function" << endl;
            break;
    }
        
    }
    
    // Returns File referance if the passed parameter is a Directory
    // and is in *this Directory
    const File& Directory::cd(const File& currentFile)const{
        
        // İf the passed parameter object is not a Directory object
        if(NULL == dynamic_cast<const Directory*>(&currentFile))
        {
            cout << currentFile.getName() << ": No such1 directory ";
            cout << "in " << getName() << endl;
            
            // Get te reference of this pointer
            const File& thisRef = dynamic_cast<const File&>(*this);
            return thisRef; // return this pointer reference
        }
        else // the passed parameter object is a Directory object
        {
            // Check if the parameter Directory object is in the Directory
            for(set<File*>::iterator it = files.begin(); it != files.end(); ++it)
            {
                // The parameter Directory object is in the *this Directory
                if(currentFile.getName() == (*it)->getName())
                {
                    // Get the reference of the it pointer
                    // Since it pointer points to a directory with the same name
                    // as currentFile
                    const File& itRef = dynamic_cast<const File&>(**it);
                    return itRef;
                }
            }
            cout << currentFile.getName() << ": No such2 directory ";
            cout << "in " << getName() << endl;

            // Get the reference of this pointer
            const File& thisRef = dynamic_cast<const File&>(*this);
            return thisRef; // return this pointer reference 
        }
    }
}
