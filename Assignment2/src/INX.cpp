#include "global.h"
#include "tools.h"

void INX(string arg,string registers[],bool flag[]){	
    int registerID = registerNumber(arg);
    if(registerID == 1 || registerID == 3 || registerID == 5){
        string data16bit = "";
        string temporary = "";	
        string s1 = "";
        string s2 = "";  
        data16bit = data16bit + registers[registerID] + registers[registerID + 1];
        temporary = increaseAddress(data16bit);
        s1 = s1 + temporary[0] + temporary[1];		
        s2 = s2 + temporary[2] + temporary[3];
        registers[registerID] = s1; 
        registers[registerID+1] = s2;
    }
    else{
        cout<<"Error: "<<arg<<"\nInvalid register pair\nThe program will quit\n";
        exit(0);
        /*Error:Invaid register pair*/
    }
}