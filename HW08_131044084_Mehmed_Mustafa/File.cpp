#include "File.h"

namespace GTU_Mehmed{
    // Constructors
    // Root directory is ~/main
    File::File():name("No name yet"), owner("No owner yet"), 
            size(0), lastMod("No last modification yet"){
        // Default constructor
        filePath = "~/main";
    } 
    File::File(string valName):name(valName), owner("No owner yet"), 
            size(0), lastMod("No last modification yet"){
        // Constructor that takes only name
        filePath = "~/main";
    }
    File::File(string valName, string valOwner):name(valName), 
        owner(valOwner), size(0), lastMod("No last modification yet"){
        // Constructor that takes name and owner
        filePath = "~/main";
    }
    File::File(string valName, string valOwner, int valSize)
            :name(valName), owner(valOwner), size(valSize), 
                                lastMod("No last modification yet"){
        // Constructor that takes name, owner and size
        filePath = "~/main";
        if(size < 0) // If the size is negative, make it positive
            size *= -1;
    }    
    File::File(string valName, string valOwner, int valSize, 
        string valLastMod):name(valName), owner(valOwner), size(valSize), 
                                lastMod(valLastMod){
        // Constructor that takes name, owner, size and last modification
        filePath = "~/main";
        if(size < 0) // If the size is negative, make it positive
            size *= -1;     
    }        
    
    // Public functions of class File
    // Setters
    void File::setName(string valName){
        name = valName;
    }
    void File::setOwner(string valOwner){
        owner = valOwner;
    }
    void File::setSize(int valSize){
        size = valSize;
    }
    void File::setLastMod(string valLastMod){
        lastMod = valLastMod;
    }
    void File::setPath(string valPath){
        filePath = valPath;
    }

    // Getters
    // Returns name
    string File::getName()const{
        return name;
    }
    // Returns owner
    string File::getOwner()const{
        return owner;
    }
    // Returns size
    int File::getSize()const{
        return size;
    }
    // Returns last modification time
    string File::getLastMod()const{
        return lastMod;
    }
    // Returns file path
    string File::path()const{
        return filePath;
    }
    
}