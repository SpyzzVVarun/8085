#include "global.h"
#include "tools.h"

void DAD(string arg,string registers[],bool flag[]){
    int registerID = registerNumber(arg);
    if(registerID == 1 || registerID == 3 || registerID == 5){
        string data16bit = "";
        string data16bitHL = "";
        string resultant = "";        
        data16bit = data16bit + registers[registerID] + registers[registerID];
        data16bitHL = data16bitHL + registers[5] + registers[6];
        int value16bit[4];
        int value16bitHL[4];
        int carry = 0;
        hexToDecimal(arg,value16bit);
        hexToDecimal(arg,value16bitHL);	  
        for(int i = 3;i>=0;i--){
        
            int value = value16bit[i] + value16bitHL[i] + carry;
            if(value >= 16)
                flag[0] = true;
            else
                flag[0] = false;
            carry = value / 16;
            value = value % 16;
            if(value>=0 && value<=9)
                resultant = (char)('0' + value) + resultant;
            else{
                switch(value){
                
                    case 10:
                        resultant = "A" + resultant;
                        break;
                    case 11:
                        resultant = "B" + resultant;
                        break;
                    case 12:
                        resultant = "C" + resultant;
                        break;
                    case 13:
                        resultant = "D" + resultant;
                        break;
                    case 14:
                        resultant = "E" + resultant;
                        break;
                    case 15:
                        resultant = "F" + resultant;
                        break;	
                }
            }
        }
        
        registers[5] = resultant[0] + resultant[1];
        registers[6] = resultant[2] + resultant[3];	
    }		
    else{
        cout<<"Error: "<<arg<<"\nInvalid data content in registet\nThe program will quit\n";
        exit(0);
        /*Error:Invalid data content in registers*/
    }
}