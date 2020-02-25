#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
    	vector<vector<int> > output;
		if(nums.size()<4)
    		return output;
		sort(nums.begin(),nums.begin()+nums.size());
		for(int i=0; i<nums.size();i++)
			cout<<nums[i]<<" ";
		cout<<endl;
		
		int first = 0;
		int second = 1;
		int third =2;
		int last = nums.size() - 1;
		while(first<nums.size()-3) {
			for(int i = first + 1; i< nums.size()-2; i++) {
				//	cout<<"first: "<<nums[first]<<" second: "<<nums[i];
				for(int j = i+1; j<nums.size()-1; j++)
				{
					int result = target - (nums[first] + nums[i] + nums[j]);
				//	cout<<" third: "<<nums[j];
				//	cout<<" result: "<<result<<endl;
					if(result<=nums[last])
						for(int k = j+1; k<=last;k++)
						{
						//	cout<<"first: "<<nums[first]<<" second: "<<nums[i];
						//	cout<<" third: "<<nums[j]<<" fourth: "<<nums[k]<<endl;
							if(nums[k]==result)
							{
								vector<int> temp;
								temp.push_back(nums[first]);
								temp.push_back(nums[i]);
								temp.push_back(nums[j]);
								temp.push_back(nums[k]);
								bool hasVector = false;
								for(int t=0;t<output.size();t++)
								{
									if(output[t][0]==temp[0]&&output[t][1]==temp[1]&&output[t][2]==temp[2]&&output[t][3]==temp[3])
										hasVector =true;
								}
								if(!hasVector)
									output.push_back(temp);
							}
						
						}
				}
			}
			first ++;
		}
		return output; 
    }
};


int main() {
	Solution s;
	int t = 0;
	int b[]= {1,0,-1,0,-2,2};
	vector<int> a(b, b+6);
	vector<vector<int> > o;
	o = s.fourSum(a, t);
	for(int i = 0; i<o.size(); i++){
		for(int j = 0; j<o[i].size();j++)
		{
			cout<<o[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
