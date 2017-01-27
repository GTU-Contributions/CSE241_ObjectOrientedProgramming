#include "TextFile.h"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

namespace GTU_Mehmed{
    // Constructors
    TextFile::TextFile():File(), textType("No type yet"){
        // Default constructor
    }
    TextFile::TextFile(string valName):File(valName){
        // Constructor that takes only name
    }
    TextFile::TextFile(string valName, string valOwner)
              :File(valName, valOwner){
        // Constructor that takes name and owner
    }
    TextFile::TextFile(string valName, string valOwner, int valSize)
              :File(valName, valOwner, valSize){
        // Constructor that takes name, owner and size
    }
    TextFile::TextFile(string valName, string valOwner, int valSize, 
        string valLastMod):File(valName, valOwner, valSize, valLastMod){
        // Constructor that takes name, owner, size and last modification
    }
    TextFile::TextFile(string valName, string valOwner, int valSize, 
        string valLastMod, string valTextType)
        :File(valName, valOwner, valSize, valLastMod), textType(valTextType){
        // Constructor that takes name, owner, size and last modification
    }
        
    // Public functions of class File
    void TextFile::setTextType(string valTextType){
        textType = valTextType;
    }
    string TextFile::getTextType()const{
        return textType;
    }
    
    bool TextFile::cp(const File& currentFile){
        cout << "cp function doesn't work on text files!" << endl;       
    }
    void TextFile::ls(string valCommand)const{
        cout << "ls function doesn't work on text files!" << endl;
    }
    const File& TextFile::cd(const File& currentFile)const{
        cout << "cd function doesn't work on text files!" << endl;
    }    
}