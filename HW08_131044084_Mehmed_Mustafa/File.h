#ifndef FILE_H
#define	FILE_H

#include <string>

using std::string;

//Abstract class
namespace GTU_Mehmed{
    class File{
    public:
        // Default constructor
        File();
        // Constructor that takes only name
        File(string valName);
        // Constructor that takes name and owner
        File(string valName, string valOwner);
        // Constructor that takes name, owner and size
        File(string valName, string valOwner, int valSize);
        // Constructor that takes name, owner, size and last modification
        File(string valName, string valOwner, int valSize, string lastMod);
        
        // Setters
        void setName(string valName);
        void setOwner(string valOwner);
        void setSize(int valSize);
        void setLastMod(string valLastMod);
        void setPath(string valPath);
        
        // Getters
        string getName()const;
        string getOwner()const;
        int getSize()const;
        string getLastMod()const;
            
        
        string path()const;

        // Pure virtual functions
        virtual bool cp(const File& currentFile) = 0;
        virtual void ls(string valCommand)const = 0;
        virtual const File& cd(const File& currentFile)const = 0;
        
    protected:
        string name;
        string owner;
        int size;
        string lastMod;
        string filePath;
    };
}
#endif	/* FILE_H */