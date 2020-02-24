#include<iostream>
using namespace std;
class Solution {
	public:
		int romanToInt(string s) {
			int answer = 0;
			for(int i=0; i<s.length(); i++) {
				if(s[i]=='V')
					answer +=5;
				if(s[i]=='L')
					answer +=50;
				if(s[i]=='D')
					answer +=500;
				if(s[i]=='M')
					answer +=1000;
				if(s[i]=='C')
				{
					if(i<s.length()-1&&s[i+1]=='D')
						answer +=400;
					else if(i<s.length()-1&&s[i+1]=='M')
						answer +=900;
					else
					{
						answer +=100;
						i--;
					}
					i++;
				}
				if(s[i]=='X')
				{
					if(i<s.length()-1&&s[i+1]=='L')
						answer +=40;
					else if(i<s.length()-1&&s[i+1]=='C')
						answer +=90;
					else
					{
						answer +=10;
						i--;
					}
					i++;
				}
				if(s[i]=='I')
				{
					if(i<s.length()-1&&s[i+1]=='V')
						answer +=4;
					else if(i<s.length()-1&&s[i+1]=='X')
						answer +=9;
					else
					{
						answer +=1;
						i--;
					}
					i++;
				}
				
			}
			return answer;
		}
};

int main() {
	Solution s;
	string a[5]={"III", "IV", "IX", "LVIII", "MCMXCIV"};
	for(int i=0; i<5; i++) 
		cout<<s.romanToInt(a[i])<<endl;
	return 0;
}
