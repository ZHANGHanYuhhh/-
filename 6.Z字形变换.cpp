#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string str;
        int total = 2*numRows-2;//һ�ֶ��ٸ��� 
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
					position = j%total;//�ж�j��total�е�λ��
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
//˼·һ���ҹ��� 
//0     8        16
//1   7 9      15
//2  6  10   14
//3 5   11 13 
//4     12
//˼·���ǿռ任ʱ�䣬��������У����ַ���ȫѹ�룬���ȡ������ 





int main()
{
	Solution s;
	int n;
	string str;
	string out;
	cout<<"�������ַ�����������"<<endl;
	while(1)
	{
		cout<<"�ַ�����";
		cin>>str;
		cout<<endl; 
		cout<<"������";
		cin>>n;
		cout<<endl;
		out = s.convert(str,n);
		cout<<out<<endl; 
	}
	return 0;
 } 
