#ifndef DIRECTORY_H
#define	DIRECTORY_H

#include "File.h"
#include <string>
#include <set>
using std::set;
using std::string;

namespace GTU_Mehmed{
    struct compFunc{
        bool operator()(File* a, File* b);
    };
    
    class Directory : public File{
    public:
        // Default copy constructor is good and enough
        // Default assignment operator is good and enough
        // Default constructor
        Directory();
        // Constructor that takes only name
        Directory(string valName);
        // Constructor that takes name and owner
        Directory(string valName, string valOwner);
        // Constructor that takes name, owner and size
        Directory(string valName, string valOwner, int valSize);
        // Constructor that takes name, owner, size and last modification
        Directory(string valName, string valOwner,
            int valSize, string valLastMod);
        
        //Destructor
        virtual ~Directory();
        
        virtual bool cp(const File& currentFile);
        virtual void ls(string valCommand)const;
        virtual const File& cd(const File& currentFile)const;
        
    private:
        // Set where we store all File pointers of the directory
        // compFunc is function which compares pointers and order them
        set<File*, compFunc> files;
    };
    
}

#endif	/* DIRECTORY_H */
