#ifndef EXECUTABLE_H
#define	EXECUTABLE_H

#include "File.h"
#include <string>

using std::string;

namespace GTU_Mehmed{
    class Executable : public File{
    public:
        // Default constructor
        Executable();
        // Constructor that takes only name
        Executable(string valName);
        // Constructor that takes name and owner
        Executable(string valName, string valOwner);
        // Constructor that takes name, owner and size
        Executable(string valName, string valOwner, int valSize);
        // Constructor that takes name, owner, size and last modification
        Executable(string valName, string valOwner,
            int valSize, string lastMod);
        // Constructor that takes name, owner, size, last mod and compiler name
        Executable(string valName, string valOwner,
            int valSize, string valLastMod, string valCompiler);
        
        
        void setCompiler(string valCompiler);
        string getCompiler()const;
        
        
        virtual bool cp(const File& currentFile);
        virtual void ls(string valCommand)const;
        virtual const File& cd(const File& currentFile)const;
        
    private:
        string compiler;
    };
}

#endif