#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string str;
        int total = 2*numRows-2;//一轮多少个数 
        if(numRows == 1)
        	return s;
		for(int i = 0; i < numRows; i++)
		{
			int j = i;
			while(j<s.size())
			{
				str+=s[j];
				if(i==0||i==numRows-1)
				{
					j += 2*numRows+-2;
				}
				else
				{
					int position, next;
					position = j%total;//判断j在total中的位置
					//cout<<"position: "<<position<<" total: "<<total<<" j:"<<j<<" "<<s[j]<<endl;
					if(position<numRows-1)
					{
						next = total - 2*position;
						j+=next;
					}
					else
					{
						next = total - position + i;
						j+=next;
					}
				//	cout<<"j: "<<j<<" "<<s[j]<<" next:"<<next<<endl; 
				}	
			}	
		//	cout<<str<<endl;
		} 
		return str;
    }
};
//思路一是找规律 
//0     8        16
//1   7 9      15
//2  6  10   14
//3 5   11 13 
//4     12
//思路二是空间换时间，开多个队列，将字符串全压入，最后取出即可 





int main()
{
	Solution s;
	int n;
	string str;
	string out;
	cout<<"请输入字符串和行数："<<endl;
	while(1)
	{
		cout<<"字符串：";
		cin>>str;
		cout<<endl; 
		cout<<"行数：";
		cin>>n;
		cout<<endl;
		out = s.convert(str,n);
		cout<<out<<endl; 
	}
	return 0;
 } 
