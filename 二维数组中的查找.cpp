#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for(int i=0;i<array.size();i++)//列 
        {
        	vector<int> t;
        	t = array[i];//行 
        	for(int j=0;j<t.size();j++)
        	{
        		if(t[j]==target)
        			return true;
        		if(t[j]>target)
				{
					break;
				} 
			}
        	
		}
		return false;
    }
};
int main()
{
	int n;
	cin>>n;
	vector<int> b;//内层 
	vector<vector<int> > a;//外层 
	for(int j=0;j<n;j++){
		b.clear();
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			b.push_back(temp);
		}
		a.push_back(b);
	}
	Solution S;
	cout<<S.Find(3,a);
	return 0;
}
