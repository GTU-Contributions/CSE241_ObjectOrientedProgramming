#ifndef TEXTFILE_H
#define	TEXTFILE_H

#include "File.h"
#include <string>

using std::string;

namespace GTU_Mehmed{
    class TextFile : public File{
    public:
        // Default constructor
        TextFile();
        // Constructor that takes only name
        TextFile(string valName);
        // Constructor that takes name and owner
        TextFile(string valName, string valOwner);
        // Constructor that takes name, owner and size
        TextFile(string valName, string valOwner, int valSize);
        // Constructor that takes name, owner, size and last modification
        TextFile(string valName, string valOwner,
            int valSize, string lastMod);
        // Constructor that takes name, owner, size, last mod and compiler name
        TextFile(string valName, string valOwner,
            int valSize, string valLastMod, string valTextType);
        
        void setTextType(string valTextType);
        string getTextType()const;
        
        virtual bool cp(const File& currentFile);
        virtual void ls(string valCommand)const;
        virtual const File& cd(const File& currentFile)const;
        
    private:
        string textType;
    };
}

#endif
