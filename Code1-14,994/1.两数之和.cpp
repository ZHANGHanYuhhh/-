#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target)
		{
			vector<int> out;
			for(int i=0;i<nums.size();i++)
			{
				for(int j=i+1;j<nums.size();j++)
				{
					if(nums[i]+nums[j]==target)
					{
						out.push_back(i);
						out.push_back(j);
						return out;
					}
				}
			}
		}
};
int main(){
	Solution s;
	vector<int> out;
	vector<int> input;
	input.push_back(2);
	input.push_back(7);
	input.push_back(11);
	input.push_back(15);
	out = s.twoSum(input,9); 
	cout<<out[0]<<" "<<out[1]<<endl;
	return 0;
}
