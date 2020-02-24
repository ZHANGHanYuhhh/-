#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int> >& grid) {
        vector<int> inner;
        stack<int> col;//��Ҫ�ı���� 
        stack<int> row;//��Ҫ�ı���� 
        int count = 0;
        int maxrow, maxcol;
		bool ifchange = true;//�ж��Ƿ������Ӹ���
		while(ifchange)
		{
			ifchange = false;
			for(int i=0;i<grid.size();i++)
			{
				maxrow = grid.size()-1;
				//���ѭ������
				inner = grid[i];
				maxcol = inner.size() -1;
				for(int j=0;j<inner.size();j++)
				{
					//�ڲ�ѭ������
					if(inner[j]==2)
					{
						col.push(j);
						row.push(i);
					
					} 
			 	}	 
			}
			//����������Ҫ�ı������
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
//ѭ������������2���丽��4�������1��Ϊ2��ֱ��û����Ҫ�任��Ϊֹ����ȷ���Ƿ����1. 
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
