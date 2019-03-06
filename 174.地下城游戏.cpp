#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int min, temp;
        vector<int> in;
        stack<vector<int> > save;
        in = dungeon[0];
        temp = in[0];
        //让temp为起点
		save.push(in);
		//起点入栈
		for 
        return temp;
    }
};
int main()
{
	Solution S;
	vector<int> inner;
	int result;
	vector<vector<int> > out;
	inner.push_back(-2);
	inner.push_back(-3);
	inner.push_back(3);
	out.push_back(inner);
	inner.clear();
	inner.push_back(-5);
	inner.push_back(-10);
	inner.push_back(1);
	out.push_back(inner);
	inner.clear();
	inner.push_back(10);
	inner.push_back(30);
	inner.push_back(-5);
	out.push_back(inner);
	inner.clear();
	result = S.calculateMinimumHP(out);
	cout<< result <<endl;
	return 0;
}
