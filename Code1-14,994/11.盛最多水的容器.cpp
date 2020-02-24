#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int maxleft, maxright, maxwater;
		maxleft = 0;
		maxright = height.size()-1;
		if(height[maxleft] < height[maxright])
			maxwater = height[maxleft] * (maxright - maxleft);
		else
			maxwater = height[maxright] * (maxright - maxleft);
		
		int i = maxleft;
		int j = maxright;
		int tempsize = 0;
		while(i != j)
		{
			// move shorter side until two points meet
			if(height[i] < height[j])
			{
				i++;
				if(height[i] < height[j])
					tempsize = height[i] * (j - i);
				else
					tempsize = height[j] * (j - i);
				if(tempsize > maxwater)
				{
					maxright = j;
					maxleft = i;
					maxwater = tempsize;
				}
			}
			else
			{
				j--;
				if(height[i] < height[j])
					tempsize = height[i] * (j - i);
				else
					tempsize = height[j] * (j - i);
				if(tempsize > maxwater)
				{
					maxright = j;
					maxleft = i;
					maxwater = tempsize;
				}
			}
		}
		return maxwater;
		//cout<<"maxright: "<<maxright<<" maxleft: "<<maxleft<<" maxsize: "<<maxwater<<endl;
    }
};

int main(){
	vector<int> a, b, c;
	Solution s;
	int v[10] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	for(int i = 0; i < 10; i++)
	{
		if(v[i] != NULL)
			a.push_back(v[i]);
	}
	s.maxArea(a);
	//
	return 0;
} 
