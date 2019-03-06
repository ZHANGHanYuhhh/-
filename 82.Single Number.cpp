#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
    	vector<int>::iterator it;
    	sort(A.begin(),A.end());
    	for(int i=0;i<A.size();i++)
    	{
    		for(int j=i+1;j<A.size();j++)
    		{
    			if(A[i]==A[j])
    			{
    				A.erase(i);
    				A.erase(*j);
				}
			}
		}
		return A[0];
        // write your code here
    }
};
int main()
{
	vector<int> A;
	int n, result;
	cin>>n;
	Solution S;
	while(n--)
	{
		int temp;
		cin>>temp;
		A.push_back(temp);
	}
	result=S.singleNumber(A);
	cout<<result<<endl;
	return 0;
}
