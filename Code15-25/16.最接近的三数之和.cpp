#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.begin()+nums.size());
		int first = 0;
		int last = nums.size()-1;
		int middle = first + 1;
		int sum = nums[first]+ nums[last] + nums[middle];
		
		int absolute = abs(sum - target);
	//	cout<<absolute<<endl;
		int answer = sum;
		while(first<nums.size()-2) {
			sum = nums[first]+ nums[last] + nums[middle];
		//	cout<<"while0 "<<sum<<" "<<nums[first]<<" "<<nums[middle]<<" "<<nums[last]<<" "<<endl;
			if(abs(sum-target)<absolute)
			{
				absolute = abs(sum - target);
				answer = sum;
			}
			while(sum>target&&middle+1!=last)
			{
				last--;
				sum = nums[first]+ nums[last] + nums[middle];
			//	cout<<"while1 "<<sum<<" "<<nums[first]<<" "<<nums[middle]<<" "<<nums[last]<<" "<<endl;
				if(abs(sum-target)<absolute)
				{
					absolute = abs(sum - target);
					answer = sum;
				}
					
			}
			while(sum<=target&&middle+1!=last)
			{
				middle ++;
				sum = nums[first]+ nums[last] + nums[middle];
			//	cout<<"while2 "<<sum<<" "<<nums[first]<<" "<<nums[middle]<<" "<<nums[last]<<" "<<endl;
				if(abs(sum-target)<absolute)
				{
					absolute = abs(sum - target);
					answer = sum;
				}
			}
			sum = nums[first]+ nums[last] + nums[middle];
			//cout<<"while3 "<<sum<<" "<<nums[first]<<" "<<nums[middle]<<" "<<nums[last]<<" "<<endl;
			if(abs(sum-target)<absolute)
			{
				absolute = abs(sum - target);
				answer = sum;
			}
			if(middle == last -1)
			{
				first++;
				middle = first +1;
				last =  nums.size()-1;
			}
			
		}
		return answer;
    }
};
int main() {
	Solution s;
	int b[9] = {-5, -5, -4, 0, 0, 3, 3, 4, 5};
	vector<int> a(b,b+9);
	int target = -2;
	cout<< s.threeSumClosest(a, target)<<endl;
	return 0;
}
