#include "header/global.h"
#include "header/tools.h"
void LXI (string arg1,string arg2,string registers[],bool flags[],map<string,string> &memory)
{
    if(arg1=="M")
    {
        string part1="",part2="";
        for(int i=0;i<2;i++)
        {
            part1+=arg2[i];
            part2+=arg2[i+2];
        }
        registers[5]=part1;
        registers[6]=part2;
    }
    else
    {
        string part1="",part2="";
        for(int i=0;i<2;i++)
        {
            part1+=arg2[i];
            part2+=arg2[i+2];
        }
        registers[registerNumber(arg1)]=part1;
        registers[registerNumber(arg1)+1]=part2;
    }
}