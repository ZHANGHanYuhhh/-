#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
		//先进行数组排序，然后再计算
		vector<vector<int> > output;
		if(nums.size()<3)
			return output;
		sort(nums.begin(), nums.begin()+nums.size());
		int count = 1;
		int num = nums[0];
		vector<int> tempnums;
		for(int i=1;i<nums.size(); i++)
		{
			if(nums[i]==num)
				count++;
			else {
				if(num==0&&count>=3)
				{
					tempnums.push_back(num);
					tempnums.push_back(num);
					tempnums.push_back(num);
					count =1;
					num = nums[i];
				}
				else if(count>=2)
				{
					tempnums.push_back(num);
					tempnums.push_back(num);
					count =1;
					num = nums[i];
				}
				else
				{
					tempnums.push_back(num);
					count =1;
					num = nums[i];
				}
			}
			if(i==nums.size()-1)
			{
				if(num==0&&count>=3)
				{
					tempnums.push_back(num);
					tempnums.push_back(num);
					tempnums.push_back(num);
					count =1;
					num = nums[i];
				}
				else if(count>=2)
				{
					tempnums.push_back(num);
					tempnums.push_back(num);
					count =1;
					num = nums[i];
				}
				else
				{
					tempnums.push_back(num);
					count =1;
					num = nums[i];
				}
			}
		}
		int minp = 0;
		int maxp = tempnums.size() - 1;
		bool start =false;
		if(tempnums.size()<3)
			return output;
		while(!start)
		{
			
			if(tempnums[minp]+tempnums[maxp]+tempnums[maxp-1]<0)
			{
				minp ++;
				if(minp==maxp-1)
					return output;					
			}
			else if(tempnums[minp]+tempnums[minp+1]+tempnums[maxp-1]>0)
			{
				maxp --;
				if(maxp==minp+1)
					return output;
			}
			else 
			{
				start = true;
			}
		}
		int i = minp;
		int j = i+1;
		int t = maxp;
		while(i<= maxp-2)
		{
			int result = tempnums[i]+tempnums[j]+tempnums[t];
			while(result<0&&j+1!=t)
			{
				j++;
				result = tempnums[i]+tempnums[j]+tempnums[t];
			}
			while(result>0&&j!=t-1)
			{
				t--;
				result = tempnums[i]+tempnums[j]+tempnums[t];
			}
			if(result==0)
			{
				vector<int> temp;
				bool hasVector = false;
				temp.push_back(tempnums[i]);
				temp.push_back(tempnums[j]);
				temp.push_back(tempnums[t]);
				for(int k=0; k<output.size(); k++)
				{
					if(temp[0]==output[k][0]&&temp[1]==output[k][1]&&temp[2]==output[k][2])
						hasVector = true;
				} 
				if(hasVector==false)
					output.push_back(temp);	
			}
			if(j==t-1)
			{
					i++;
					j = i+1;
					t = maxp;
			}
			
			else {
				j++;
				}
    	}
    	return output;
    }
};

int main() {
	Solution s;
	int d[999] ={-13,11,11,0,-5,-14,12,-11,-11,-14,-3,0,-3,12,-1,-9,-5,-13,9,-7,-2,9,-1,4,-6,-13,-7,10,10,9,7,13,5,4,-2,7,5,-13,11,10,-12,-14,-5,-8,13,2,-2,-14,4,-8,-6,-13,9,8,6,10,2,6,5,-10,0,-11,-12,12,8,-7,-4,-9,-13,-7,8,12,-14,10,-10,14,-3,3,-15,-14,3,-14,10,-11,1,1,14,-11,14,4,-6,-1,0,-11,-12,-14,-11,0,14,-9,0,7,-12,1,-6};

	vector<int> a, b, c(d,d+99);
	vector<vector<int> > answer;
	a.push_back(-2);
	a.push_back(0);
	a.push_back(1);
	a.push_back(1);
	a.push_back(2);
	//a.push_back(-4);
	b.push_back(1);
	b.push_back(2);
	b.push_back(-2);
	b.push_back(-1);
	answer = s.threeSum(c);
	for(int i=0; i<answer.size(); i++)
	{
		for(int j=0; j<answer[i].size(); j++)
			cout<<answer[i][j]<<"  ";
		cout<<endl;
	}
	return 0;
}
