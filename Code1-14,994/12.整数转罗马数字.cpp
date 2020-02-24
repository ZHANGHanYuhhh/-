#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string th[3] = {"M", "MM", "MMM"}; //千位对应的罗马字母 
    	string hu[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; //百位对应的罗马字母
    	string te[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; //十位对应的罗马字母
    	string in[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; //个位对应的罗马字母
    	
		int thousand;
		int hundred;
		int ten; 
		int integer;
		int temp;
		string output;
		thousand = num / 1000;
		temp = num % 1000;
		hundred = temp / 100;
		temp = temp % 100;
		ten = temp / 10;
		integer = temp %10;
		//cout<<"thousand: "<<thousand<<" hundred: "<<hundred<<" ten: "<<ten<<" integer: "<<integer<<endl;
		if(thousand > 0)
			output += th[thousand - 1];
		if(hundred > 0)
			output += hu[hundred - 1];
		if(ten > 0)	
			output += te[ten - 1];
		if(integer > 0)	
		 	output += in[integer - 1];
		//cout<< output<<endl;	
		return output;
		
    }
};

int main(){
	int input[12]={1, 22, 33, 44, 99, 199, 1994, 2131, 100, 10, 4};
	Solution s;
	for(int i=0;i<11; i++) 
		s.intToRoman(input[i]);
	return 0;
}

