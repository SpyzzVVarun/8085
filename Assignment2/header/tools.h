#ifndef _TOOLS_H
#define _TOOLS_H

string hexAdd(string,string,bool[],bool);
string hexSub(string,string,bool[],bool);
string hexAdd16bit(string,string,bool[],bool);
string hexSub16bit(string,string,bool[],bool);
void hexToDecimal(string,int[]);
int registerNumber(string);
string increaseAddress(string);
string complement(string);
int operationSize(string);
string execution(string, string[], bool[], map<string,string>&,string);
string updatedAddress(string,map<string,string>&);
string nextAddress(string ,int);

#endif