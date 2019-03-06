#include<iostream>
using namespace std;
string check(string str)
{
	int i=0;
	if(str[0]>'2')
		str[0]='0';
	//时不合法 
	if(str[0]=='2'&&str[1]>'3')
		str[0]='0';
	//时不合法
	if(str[3]>'5')
		str[3]='0';
	if(str[6]>'5')
		str[6]='0';
	return str; 
};//判断是否合法 
int main()
{
	string str;
	string output;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str;
		if(str=="\n")
			cin>>str;
		str=check(str);
		cout<<str<<endl;
	
	}
	system("pause");
	//cout<<output;
	return 0;
}
