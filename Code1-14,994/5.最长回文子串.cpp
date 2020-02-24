#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {//以一点或两点为中心，向外扩展 
        int firstp = 0;//指针位置
		int max =0;
		string maxstr="";
		int breakmark=0;
		while(firstp<s.length())
		{
			int temp =ifPalindromic(s,firstp,firstp);//以一点为中心 
	//		cout<<"temp1:"<<temp<<endl;
			if(temp>max)
			{
				max=temp;
				int	i=firstp-(temp-1)/2;
				int j=firstp+(temp-1)/2;
	//			cout<<"i: "<<i<<" j: "<<j<<endl;
				maxstr="";
				if(i<=j)
				{
					for(int t=i;t<=j;t++)
					{
						maxstr+=s[t];
					}
				}
			}
			temp =ifPalindromic(s,firstp,firstp+1);//以两点为中心 
//			cout<<"temp2:"<<temp<<endl;
			if(temp>max)
			{
				max=temp;
				int	i=firstp-temp/2+1;
				int j=firstp+temp/2;
	//			cout<<"i: "<<i<<" j: "<<j<<endl;
				maxstr="";
				if(i<=j)
				{
					for(int t=i;t<=j;t++)
					{
						maxstr+=s[t];
					}
				}
				
			}
			firstp++; 
		}
		return maxstr;
		
    }
    int ifPalindromic(string s, int startL, int startR) {
    	int single = 0;
    	int i = startL;
		int j = startR; 
		if(j==i)
			single = 1;	
		if(startR>=s.length())
			return 1;
    	while(s[i]==s[j]&&0<i&&j<s.length()-1)
    	{
    		i--;
			j++;
		}
//		cout<<"s[i]:"<<s[i]<<"i:"<<i<<" s[j]:"<<s[j]<<"j:"<<j<<endl;
		if(s[i]!=s[j]&&0<=i&&j<s.length())
		{
				i++;
				j--;
		} 
			return j-i+1;
    		
	}
};

int main(){
	string str;
	string max;
	Solution s;
	while(cin>>str)
	{
		max=s.longestPalindrome(str);
		cout<<max<<endl;
	}
	return 0;
}
