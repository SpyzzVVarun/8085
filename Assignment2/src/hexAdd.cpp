#include "global.h"
#include "tools.h"
/*Carry flag remains unaffected in INR and DCR operations*/

string hexAdd(string arg1,string arg2,bool flag[],bool carry){
	
	string resultant = "";
	int variable;
	int value1[5] = {0,0};
	int value2[5] = {0,0};
	int tempAnswer[2];
	hexToDecimal(arg1,value1);
	hexToDecimal(arg2,value2);
	
	tempAnswer[1] = value1[1] + value2[1];
	if(tempAnswer[1]>=16){
	
		tempAnswer[1] = tempAnswer[1]%16;
		value1[0]++;
		flag[4] = true;
		}
	tempAnswer[0] = value1[0] + value2[0];
	if(tempAnswer[0]>=16){
	
		tempAnswer[0] = tempAnswer[0]%16;
		if(carry == true)
			flag[0] = true;
	}
	
	variable = tempAnswer[0]*16 + tempAnswer[1];
	bitset<8> dataInBinary(variable);
	/*Setting parity flag*/
	int parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
		flag[2] = true;
	else
		flag[2] = false;
	/*Setting sign flag*/
	flag[7] = dataInBinary[7];
	/*Setting zero flag*/
	if(parity == 0)
		flag[6] = true;
	
	/*Convert decimal data to hexadecimal and store in accumulator*/
	for(int i = 1;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0' + tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}
	
	return resultant;
}

string hexAdd16bit (string arg1,string arg2,bool flag[],bool check)
{
	int l1=arg1.length();
	int l2=arg2.length();
	string hex="";
	if(l1==1&&l2==4)
	{
		int value1[4]={0,0,0,0};
		for(int i=0;i<l1;i++)
		{
			if(arg1[i]>='0'&&arg1[i]<='9')
				value1[i]=(int)(arg1[i]-'0');
			else if(arg1[i]>='A'&&arg1[i]<='Z')
				value1[i]=(int)(arg1[i]-'A');
		}
		int i=l1-1;
		value1[l1-1]++;
		while(value1[i]>=16)
		{
			value1[i]=value1[i]%16;
			if(i==0)
			{
				flag[0]=true;
				break;
			}
			else
				value1[--i]++;
		}
		int value=value1[0]*16*16*16+value1[1]*16*16+value1[2]*16+value1[3];
		bitset<16>str(value);
		flag[7]=str[15];
		int parity=str.count();
		if(parity==0)
			flag[6]=true;
		else if(parity%2==0)
			flag[2]=true;
		else if(parity%2==1)
			flag[2]=false;
		for(int i=0;i<l1;i++)
		{
			if(value1[i]>=0&&value1[i]<=9)
				hex+=(char)value1[i];
			else if(value1[i]>=10&&value1[i]<=15)
				hex+=(char)('A'+(value1[i]-10));
		}
	}
	return hex;
}
