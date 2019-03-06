#include<iostream>
using namespace std;
int main()
{
	int R, W, L;
	cin>>L>>R>>W;
	if(R>L-W)
		cout<<"DEADLOCK"<<endl;
	else
		cout<<"OK"<<endl; 
	return 0;
 } 
