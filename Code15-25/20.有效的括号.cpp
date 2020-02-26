#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
		if(s=="")
			return true;
		stack<char> temp;
        if(s[0]==']'||s[0]==')'||s[0]=='}')
            return false;
		for(int i=0; i<s.length();i++)
		{
			if(s[i]=='(')
				temp.push(')');
            else if(s[i]=='[')
                temp.push(']');
            else if(s[i]=='{')
                temp.push('}');
			else {
                if(temp.empty())
                    return false;
				char check = temp.top();
               // cout<<check<<endl;
				temp.pop();
				if(check!=s[i])
					return false;
			}
		}
		if(!temp.empty())
			return false;
		return true;
	
    }
};
int main() {
	Solution s;
	string a;
	s.isValid(a);
	return 0;
}
