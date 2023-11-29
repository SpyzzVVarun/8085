// This file is part of an 8085 emulator project.
// It contains the implementation of the MVI (Move Immediate) instruction.

#include "global.h"
#include "tools.h"

void MVI (string arg1,string arg2,string registers[],bool flags[],map<string,string> &memory){
    int l1=arg1.length();
    int l2=arg2.length();
    
    // Check if the arguments are valid
    if(l1==1&&l2==2){
        if(arg1=="M"){
            // If arg1 is "M", move the immediate data (arg2) to the memory location specified by HL register pair
            string address=registers[5]+registers[6];
            if(validityData(arg2))
                memory[address]=arg2;
            else{
                cout<<"Error: "<<"Invalid content\nThe program will quit\n";
                exit(0);
            }
        }
        else if(validityRegisters(arg1)&&validityData(arg2)){
            // If arg1 is a valid register and arg2 is valid data, do nothing
            cout << "Do Nothing\n";
        }
        else{
            // Invalid content
            cout<<"Error: "<<"Invalid content\nThe program will quit\n";
            exit(0);
        }
    }
    else{
        // Invalid content
        cout<<"Error: "<<"Invalid content\nThe program will quit\n";
        exit(0);
    }
}