#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string SamePrefix = "";
		int i = 0;
		if(strs.empty())
			return "";
		while(i<strs[0].length())
		{
			for(int j = 0; j<strs.size(); j++)
			{
				if(i<strs[j].length())
				{
					if(strs[j][i]!=strs[0][i]&&SamePrefix =="")
						return ""; 
					else if(strs[j][i]!=strs[0][i]&&SamePrefix !="")
						return SamePrefix;
				}
				else
					return SamePrefix;
			}
			SamePrefix += strs[0][i];	
			i++;
		}
		return SamePrefix;
		
    }
};

int main() {
	vector<string> a;
	Solution s;
	cout<<s.longestCommonPrefix(a)<<endl;
	return 0;
}
