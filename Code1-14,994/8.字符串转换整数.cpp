#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {//�����ʽΪ"�ַ���"����ͷ�� " ;
    	
        long long temp = 0;
        int maxlength = str.length() ;
        bool negative = false;
        int out =0;
        int t = 0;
        if(str[t]=='"')//�жϿ�ͷ 
        	t++;
        while(str[t]==' ')//Ѱ�ҵ�һ���ǿ��ַ� 
        {
        	t++;
		}
		if(str[t]!='-'&&str[t]!='+'&&(str[t]<'0'||str[t]>'9'))//��һ���ǿ��ַ��������ֻ���+-����0 
			return 0;
		if(str[t]=='-')
		{
			
			negative = true;
			t++;
			if('9'<str[t]||str[t]<'0')//+��-����Ҫ������ 
			{
				return 0;
			}
				
		}
	    if(str[t]=='+')
		{
			negative = false;
			t++;
			if('9'<str[t]||str[t]<'0')//+��-����Ҫ������ 
			{
				return 0;
			}
				
		}
		while('0'<=str[t]&&str[t]<='9'){
			if(temp>INT_MAX&&!negative)//С������Խ�� 
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
		if(out!=temp&&negative)//����Խ��
		 	out = INT_MIN;
		if(out!=temp&&!negative)//����Խ�� 
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
