#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		 int result;
		 int startnum ;
		 int count = 0;
		 vector<vector<int> > out;
		 for(int i=0;i< candidates.size();i++)
		 {
		 	startnum = i+1;
		 	vector<int> temp;
		 	result = target- candidates[i];
		 	count = 0;
		 	while(result>0&&startnum<candidates.size())
			{
				cout<<"count:"<<count<<" result:"<<result<<endl<<endl;
				temp = findS(candidates, result, startnum);
				if(temp[0]!=-1)
				{
					temp.push_back(candidates[i]);
					while(count>0)
					{
						temp.push_back(candidates[i]);
						count--;
					}
					out.push_back(temp);		
				} 
				result = result- candidates[i];
				count++;
			}
			if(target%candidates[i]==0)
			{
				result = target;
				temp.clear();
				while(result!=0)
				{
					temp.push_back(candidates[i]);
					result-=candidates[i];
				}
				out.push_back(temp);
			}   
			
		 }
		for(int i=0;i<out.size();i++)
		{
			sort(out[i].begin(),out[i].end());
		}
		return out;
		 
    }
    vector<int> findS(vector<int>& candidates, int target, int startnum){
    	int result;
    	
    	vector<int> noanswer;
    	for(int i=startnum;i< candidates.size();i++)
		 {
		 	vector<int> temp;
		 	result = target- candidates[i];
		 	cout<<"target:"<<target<<" startnum: "<<candidates[i]<<" result: "<<result<<endl;
		 	if(result>0)//如果大于0，递归 
			{
				temp = findS(candidates, result, startnum);
				if(temp[0]!=-1)
				{
					temp.push_back(candidates[i]);
					return temp;		
				}       
			}
			else if(result==0)//如果等于0，加入vector返回 
			{
				temp.push_back(candidates[i]);
				return temp;
			}
			 
		}
		noanswer.push_back(-1);
		return noanswer;
		 
	}
};

//递归思想 
int main()
{
	Solution S;
	vector<int> input;
	input.push_back(7);
	input.push_back(3);
	input.push_back(2);
	vector<vector<int> >output;
	output = S.combinationSum(input,18);
	for(int i=0;i<output.size();i++)
	{
		vector<int> temp;
		temp = output[i];
		for(int j=0;j<temp.size();j++)
		{
			cout<<temp[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
