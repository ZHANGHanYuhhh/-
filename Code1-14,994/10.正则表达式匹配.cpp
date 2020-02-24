#include<iostream>
#include<string>
using namespace std;
 
class Solution {
public:
    bool isMatch(string s, string p) {
    	if(s==""&&p=="")
    		return true;
    	if(s==""&&p!="")
    		return false;
    	if(s!=""&&p=="")
    		return false;
       	for(int t=0;t<p.size();t++)
       	{
       		char last;
       		if(p[t]=='*')
       			last = findLast(p,t);
       		if(p[t]==s[0]||p[t]=='.'||(p[t]=='*'&&last==s[0]))//匹配到第一个字符
			{
				bool check = true;
				int j = t;
				for(int i=0;i<s.length();i++){
					char last2;
       				if(p[j]=='*')
       					last2 = findLast(p,j);
					if(s[i]!=p[j]&&p[j]!='.'&&)
				}	
			} 
	   	}
    }
    char findLast(string s, int p) {
		char last;
		while(s[p]=='*'&&p>=0)
		{
			p--;	
		}
		if(p>=0)
		{
			last = s[j];	
		}
		return last;	
	}
};

int main()
{
	bool out;
	Solution s;
	string str1;
	string str2;
	while(cin>>str1)
	{
		cout<<"请输入第二个字符串:"<<endl;
		cin>>str2;
		out = s.isMatch(str1,str2);
		cout<<out<<endl;
	}
	return 0;
}
