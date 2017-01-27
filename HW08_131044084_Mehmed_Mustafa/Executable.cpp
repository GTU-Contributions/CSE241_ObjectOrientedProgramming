#include "Executable.h"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

namespace GTU_Mehmed{
    // Constructors
    Executable::Executable():File(), compiler("No compiler yet"){
        // Default constructor
    }
    Executable::Executable(string valName):File(valName){
        // Constructor that takes only name
    }
    Executable::Executable(string valName, string valOwner)
              :File(valName, valOwner){
        // Constructor that takes name and owner
    }
    Executable::Executable(string valName, string valOwner, int valSize)
              :File(valName, valOwner, valSize){
        // Constructor that takes name, owner and size
    }
    Executable::Executable(string valName, string valOwner, int valSize, 
        string valLastMod):File(valName, valOwner, valSize, valLastMod){
        // Constructor that takes name, owner, size and last modification
    }
    Executable::Executable(string valName, string valOwner, int valSize, 
        string valLastMod, string valCompiler)
            :File(valName, valOwner, valSize, valLastMod), compiler(valCompiler){
        // Constructor that takes name, owner, size and last modification
    }
    
    
    // Public functions of class File
    void Executable::setCompiler(string valCompiler){
        compiler = valCompiler;
    }
    string Executable::getCompiler()const{
        return compiler;
    }
    
    
    bool Executable::cp(const File& currentFile){
        cout << "cp function doesn't work on executable files!" << endl;
    }
    void Executable::ls(string valCommand)const{
        cout << "ls function doesn't work on executable files!" << endl;
    }
    const File& Executable::cd(const File& currentFile)const{
       cout << "cd function doesn't work on executable files!" << endl; 
    }    
}