#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {//输入格式为"字符串"，开头有 " ;
    	
        long long temp = 0;
        int maxlength = str.length() ;
        bool negative = false;
        int out =0;
        int t = 0;
        if(str[t]=='"')//判断开头 
        	t++;
        while(str[t]==' ')//寻找第一个非空字符 
        {
        	t++;
		}
		if(str[t]!='-'&&str[t]!='+'&&(str[t]<'0'||str[t]>'9'))//第一个非空字符不是数字或者+-返回0 
			return 0;
		if(str[t]=='-')
		{
			
			negative = true;
			t++;
			if('9'<str[t]||str[t]<'0')//+，-后面要跟数字 
			{
				return 0;
			}
				
		}
	    if(str[t]=='+')
		{
			negative = false;
			t++;
			if('9'<str[t]||str[t]<'0')//+，-后面要跟数字 
			{
				return 0;
			}
				
		}
		while('0'<=str[t]&&str[t]<='9'){
			if(temp>INT_MAX&&!negative)//小心数组越界 
				return INT_MAX;
			if(temp>INT_MAX&&negative)
				return INT_MIN;
			temp *= 10;
			temp += str[t]-'0';
			t++;
		}
		if(negative)
			temp = -temp;
		out = temp;
		if(out!=temp&&negative)//负数越界
		 	out = INT_MIN;
		if(out!=temp&&!negative)//正数越界 
			out = INT_MAX;
			return  out;
    }
    
};

int main()
{
	string str;
	int out;
	Solution s;
	while(getline(cin,str))
	{
		out = s.myAtoi(str);
		cout<<out<<endl;
	}
	return 0;
}
