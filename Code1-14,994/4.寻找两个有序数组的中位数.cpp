#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        
        vector<int> temp;
		int counta = 0, countb = 0;//记录数组遍历的位置 
		double answer;
		while(counta<nums1.size()&&countb<nums2.size())
		{
			if(nums1[counta]<=nums2[countb])
			{
				temp.push_back(nums1[counta]);
				counta++;
			}
			else if(nums1[counta]>nums2[countb])
			{
				temp.push_back(nums2[countb]);
				countb++;
			}
		}
		while(counta<nums1.size()) 
		{
			temp.push_back(nums1[counta]);
			counta++;
		}
		while(countb<nums2.size()) 
		{
			temp.push_back(nums2[countb]);
			countb++;
		}
		if(length%2==0)
		{
			//cout<<"length"<<length<<endl;
			//cout<<temp[length/2-1]<<" "<<temp[length/2]<<endl;
			answer = temp[length/2-1] + temp[length/2];
			answer = answer * 0.5;
		}
		else
		{
			answer = temp[length/2];
			double(answer)= double(answer*1.0);
		}
		return double(answer);
    }
};

int main()
{
	vector<int> num1, num2;
	double ans;
	Solution s;
	num1.push_back(1);
	num1.push_back(3);

	ans = s.findMedianSortedArrays(num1,num2);
	cout<< ans <<endl;
	return 0;
}
