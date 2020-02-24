#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str;
        int count=0, max =0;
        for(int i=0;i<s.length();i++)
        {
        	int n = ifHas(str, s[i]);//判断字符是否在子串内 
			if(n!=-1)//子串存在该字符,将字符串首位移动到该字符后一位 
			{
				string temp = "";
				for(int j = n+1; j<str.length();j++) 
				{
					temp+=str[j];		
				}
				count=str.length()-n;
				temp += s[i];
				str = temp;
				
			}
			else
			{
				str+=s[i];
				count++;
				if(count>max)
				{
					max = count;
				}
			 } 
		}
		return max;
    }
    int ifHas(string s, char c) {
    	//cout<<"s:"<<s<<endl;
    	for(int i=0; i<s.length(); i++){
    		if(s[i]==c)
    		{
    			return i;
			}
		}
		return -1;
	}
};

int main()
{
	int max;
	string n;
	cin>>n;
	Solution s;
	max = s.lengthOfLongestSubstring(n);
	cout<<max<<endl; 
	return 0;
}
