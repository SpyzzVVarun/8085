#include "header/global.h"
#include "header/tools.h"

string nextAddress(string str,int n){

	int array[4];
	string result = "";
	hexToDecimal(str,array);
	int i = 3;
	array[i]+=n;
	while(array[i]>=16){

		array[i] = array[i]%16;
		array[i-1]++;
		i--;
	}
	for(int i = 0;i<4;i++){

		if(array[i]>=0 && array[i]<=9)
			result = result + char('0' + array[i]);
		else
			result = result + char('A' + (array[i] - 10));
	}
	return result;
}