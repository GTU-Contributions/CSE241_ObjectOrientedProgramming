#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <set>       
#include "File.h"
#include "Directory.h"
#include "Executable.h"
#include "TextFile.h"

using namespace std;
using namespace GTU_Mehmed;

int main(){

    // Root directory is ~/main
    // Every created file in main has default path ~/main   
    
    // Create A directory and copy inside aexe and atxt
    Directory a("A", "Mehmed", 4096, "09/11/2001");
        // Create hidden executable File
        Executable aexe(".Aexe", "user", 1024, "10/11/2001", "g++");
        // Create text File
        TextFile atxt("Atxt", "user", 128, "10/11/2001", "Unicode");
        a.cp(aexe); // Copy executable file aexe to A directory
        a.cp(atxt); // Copy text file atxt to A directory        
    
    // Create B directory and copy inside bexe and btxt
    Directory b("B", "Mehmed", 4096, "10/11/2001");
        // Create executable File
        Executable bexe("Bexe", "user", 1024, "10/11/2001", "visual C++");
        // Create text File
        TextFile btxt("Btxt", "user", 128, "10/11/2001", "Ascii");
        b.cp(bexe); // Copy executable file bexe to B directory
        b.cp(btxt); // Copy text file btxt to B directory
    
    // Create C directory
    Directory c("C", "Mehmed", 4096, "11/11/2001");
        // Create hidden executable File
        Executable cexe(".Cexe", "user", 1024, "10/11/2001", "visual C++");
        // Create hidden text File
        TextFile ctxt(".Ctxt", "user", 128, "10/11/2001", "Ascii");
        c.cp(cexe); // Copy executable file bexe to B directory
        c.cp(ctxt); // Copy text file btxt to B directory
    
    // Create D directory and copy inside dexe and dtxt
    Directory d("D", "Mehmed", 4096, "12/11/2001");
        // Create executable File
        Executable dexe("Dexe", "user", 1024, "12/11/2001", "NetBeans");
        // Create text File
        TextFile dtxt("Dtxt", "user", 128, "12/11/2001", "Unicode");
        d.cp(dexe); // Copy executable file cexe to C directory
        d.cp(dtxt); // Copy text file ctxt to C directory
        
    // Create S directory that is hidden and copy inside sexe and stxt
    Directory s(".S", "Mehmed", 4096, "15/11/2001");
        // Create executable File
        Executable sexe("Sexe", "user", 1024, "15/11/2001", "NetBeans");
        // Create text File
        TextFile stxt("Stxt", "user", 128, "15/11/2001", "Unicode");
        s.cp(sexe); // Copy executable file sexe to S directory
        s.cp(stxt); // Copy text file stxt to S directory   

    // Create Deneme directory
    Directory deneme("Deneme", "System", 4096, "14/11/2001");
         // Create text File
        TextFile denemeTxt("DenemeTxt", "Mehmed", 128, "14/11/2001", "Unicode");
        deneme.cp(denemeTxt); // Copy text file denemeTxt to Deneme directory
        
        deneme.cp(a); // Copy A directory and everything inside A to Deneme directory
        deneme.cp(b); // Copy B directory and everything inside A to Deneme directory
        deneme.cp(c); // Copy C directory and everything inside A to Deneme directory
        deneme.cp(d); // Copy D directory and everything inside A to Deneme directory
        deneme.cp(s); // Copy S directory and everything inside S to Deneme directory
    
    cout << "---------- TEST deneme.ls() --------------------" << endl;
    deneme.ls("");
    cout << "-----------TEST END deneme.ls() --------------------" << endl << endl;        

    cout << "---------- TEST deneme.ls(a) --------------------" << endl;
    deneme.ls("a");
    cout << "-----------TEST END deneme.ls(a) --------------------" << endl << endl;
    
    cout << "---------- TEST deneme.ls(l) --------------------" << endl;
    deneme.ls("l");
    cout << "-----------TEST END deneme.ls(l) --------------------" << endl << endl;
    
    cout << "---------- TEST deneme.ls(la) --------------------" << endl;
    deneme.ls("la");
    cout << "-----------TEST END deneme.ls(la) --------------------" << endl << endl;    
    
    cout << "---------- TEST deneme.ls(lR) --------------------" << endl;
    deneme.ls("lR");
    cout << "-----------TEST END deneme.ls(lR) --------------------" << endl << endl;         
        
    cout << "---------- TEST deneme.ls(lRa) --------------------" << endl;
    deneme.ls("lRa");
    cout << "-----------TEST END deneme.ls(lRa) --------------------" << endl << endl;  
    
    
    // Error, denemeTxt is not a Directory object    
    const File& temp = deneme.cd(denemeTxt); 
    
    // Gets the reference of C directory in the Deneme directory
    const File& temp2 = deneme.cd(c); 
    // Successful since C is a Directory in Deneme directory
    cout << endl;
    
    cout << "+++++++++++++++İNDEPENDENT COPY TEST+++++++++++++++++++" << endl;

    Directory m("M", "Mehmed", 4096, "09/11/2001");
    Executable mexe("Mexe", "user", 1024, "10/11/2001", "g++");
    Directory n("N", "SYSTEM", 4096, "09/11/2001");
    
    m.cp(mexe); // Copy mexe to M directory
    n.cp(m); // Copy M directory and everything inside to N directory
    
    cout << "-------------İnside N-------------" << endl;
    n.ls("lR"); // Print everything recursively in N directory
    cout << "-------------İnside N-------------" << endl;
    cout << endl;
    
    Executable pexe("Pexe", "user", 1024, "10/11/2001", "g++");
    m.cp(pexe); // Copy pexe to M directory
    
    cout << "-------------İnside M after cp pexe to M-------------" << endl;
    m.ls("lR"); // Print everything recursively in M directory
    cout << "-------------İnside M after cp pexe to M-------------" << endl;
    cout << endl;
    
    cout << "-------------N is unchanged cuz its independent copy-------------" << endl;
    n.ls("lR"); // Print everything recursively in N directory
    cout << "-------------N is unchanged cuz its independent copy-------------" << endl;
    
    cout << "+++++++++++END İNDEPENDENT COPY TEST+++++++++++++++++++" << endl;
    
    return 0;
}