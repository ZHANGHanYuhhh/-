#include<iostream>
#include<vector>
#include<string>
using namespace std;
int initial = 0;

class Solution {
public:

	vector<vector<char> > numToLetter;
	void initialVector() {
		char l1[3] = {'a','b','c'};
		char l2[3] = {'d','e','f'};
		char l3[3] = {'g','h','i'};
		char l4[3] = {'j','k','l'};
		char l5[3] = {'m','n','o'};
		char l6[4] = {'p','q','r','s'};
		char l7[3] = {'t','u','v'};
		char l8[4] = {'w','x','y','z'};
		vector<char> v1(l1,l1+3);
		vector<char> v2(l2,l2+3);
		vector<char> v3(l3,l3+3);
		vector<char> v4(l4,l4+3);
		vector<char> v5(l5,l5+3);
		vector<char> v6(l6,l6+4);
		vector<char> v7(l7,l7+3);
		vector<char> v8(l8,l1+4);
		numToLetter.push_back(v1);
		numToLetter.push_back(v2);
		numToLetter.push_back(v3);
		numToLetter.push_back(v4);
		numToLetter.push_back(v5);
		numToLetter.push_back(v6);
		numToLetter.push_back(v7);
		numToLetter.push_back(v8);
	}
	vector<string> letterCombinations(string digits) {
		vector<string> output;
		if(digits=="")
			return output;
		if(initial ==0){
			initial = 1;
			initialVector();
		}//初始化对应关系 
		vector<string> temp;
		//抛去第一个，其余字符串递归，最后相接
		char first = digits[0];
		if(digits.length()>1)
		{
			string rest_string = digits.substr(1, digits.length());
			temp = letterCombinations(rest_string);
		}
		int num = first - '0';
		vector<char> firstletter = numToLetter[num-2];
		for(int i=0; i<firstletter.size();i++)
		{
			for(int j=0; j<temp.size(); j++)
			{
				string newstr = firstletter[i] + temp[j];
				output.push_back(newstr);
			}
			if(temp.size()==0)
			{
				char *letter = new char(firstletter[i]);
				string newstr(letter);
				output.push_back(newstr);
				delete(letter);
			}
		}
			
		return output;
		
	}
}; 

int main() {
	Solution s;
	vector<string> answer;
	string digits = "";
	answer = s.letterCombinations(digits);
	for(int i=0; i<answer.size(); i++) {
		cout<<answer[i]<<endl;
	}
	return 0;
}
