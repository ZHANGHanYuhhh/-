#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int> >& grid) {
        vector<int> inner;
        stack<int> col;//需要改变的列 
        stack<int> row;//需要改变的行 
        int count = 0;
        int maxrow, maxcol;
		bool ifchange = true;//判断是否有橘子腐烂
		while(ifchange)
		{
			ifchange = false;
			for(int i=0;i<grid.size();i++)
			{
				maxrow = grid.size()-1;
				//外层循环，行
				inner = grid[i];
				maxcol = inner.size() -1;
				for(int j=0;j<inner.size();j++)
				{
					//内层循环，列
					if(inner[j]==2)
					{
						col.push(j);
						row.push(i);
					
					} 
			 	}	 
			}
			//遍历完所有要改变的橘子
			while(col.empty()!=true){
				
				int c, r;
				c = col.top();
				r = row.top();
				col.pop();
				row.pop();
				if(c+1<=maxcol&&grid[r][c+1]==1)
				{
					grid[r][c+1] =2;
					ifchange = true;
					
				}	
				if(c-1>=0&&grid[r][c-1]==1)
				{
					grid[r][c-1] =2;
					ifchange = true;
					
				}
				if(r+1<=maxrow&&grid[r+1][c]==1)
				{
					grid[r+1][c] =2;
					ifchange = true;
					
				}
				if(r-1>=0&&grid[r-1][c]==1)
				{
					grid[r-1][c] =2;
					ifchange = true;
					
				}
				
			}
			if(ifchange == true)
				count++; 
		}
		for(int i=0;i<grid.size();i++)
		{
			inner = grid[i];
			for(int j=0;j<inner.size();j++)
			{
				if(inner[j]==1)
				{
					return -1;
				}
			}
		}
		return count;
		
		 
    }
};
//循环遍历，遇到2将其附近4个方向的1变为2，直到没有需要变换的为止，再确认是否存在1. 
int main()
{
	Solution s;
	int result;
	vector<int> inner;
	vector<vector<int> > outer;
	inner.push_back(2);
	inner.push_back(1);
	inner.push_back(1);
	outer.push_back(inner);
	inner.clear();
	inner.push_back(0);
	inner.push_back(1);
	inner.push_back(1);
	outer.push_back(inner);
	inner.clear();
	inner.push_back(1);
	inner.push_back(0);
	inner.push_back(1);
	outer.push_back(inner);
	result = s.orangesRotting(outer);
	cout<<result<<endl;
	return 0;
}
