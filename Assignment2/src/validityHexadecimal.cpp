// This file is part of an 8085 emulator project.

#include "header/global.h"
#include <string>

// Function to check if a given string represents a valid hexadecimal number.
bool checkHex(string data, int l){

    for(int i=0;i<l;i++){
        if(((data[i]>='0' && data[i]<='9')||(data[i]>='A' && data[i]<='F')))
            continue;
        else
            return false;
    }
    return true;
}

// Function to check the validity of a hexadecimal number.
bool validityHexadecimal(string data){
    bool flag;
    int l = data.length();
    if((l == 2 || l == 4) && checkHex(data,l))
        return true;
    return false;
}