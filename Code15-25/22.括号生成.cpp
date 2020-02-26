#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool isEnd(string s) {
		for(int i=0; i<s.length();i=i+2)
		{
			if(s[i] != '(')
				return false;
		}
		return true;
	}
	/*移动方法，初始化(((())))，最终结果偶数位都为(,即()()()()，每次只移动最后一个(，移动到倒数第二位时，重新生成字符串,
	生成方法为，从最后一位(开始向前遍历，并且记录遇到的(),遇到)计数器加1，遇到(减1，如果遇到（时计数器为0则继续向前，即
	如这种情况(())()()，倒数第二个(的计数器的值为0，表示无法移动该位，继续向前，直到找到一个(，在该位的计数器值大于0；此时
	将该位前字符串不动，该位替换为），并且按照之前剩余（）数，生成新字符串，上述字符串生成为：()((()))，之后继续移动最后一位
	的（,直到达到最终状态。	 
	*/ 
    vector<string> generateParenthesis(int n) {
		vector<string> output;
		if(n==0)
			return output;
		string str;
		for(int i=0;i<n;i++)
		{
			str += "(";
		}
		for(int i=0;i<n;i++)
		{
			str += ")";
		}
		output.push_back(str);
		int lastLeft = n-1;
		while(!isEnd(str))
		{
			while(lastLeft!=str.length()-2){
				str[lastLeft] = ')';
				str[lastLeft+1] = '(';
				lastLeft = lastLeft + 1;
				output.push_back(str);
			}
			//寻找要后移的左括号
			int target = lastLeft;
			int count = 0;
			int countleft = 1;
			int countright = 1;
			while(target!=0)
			{
				target--;
				if(str[target]==')')
				{
					count++;
					countright ++;
				}
				else if(str[target]=='('&&count!=1&&!isEnd(str)) //非()()这样 
				{
					countleft ++;
					countright --;
					string newstr = str.substr(0,target);
					newstr += ")";
					for(int i=0; i<countleft; i++)
						newstr += "(";
					for(int i=0; i<countright; i++)
						newstr += ")";
					str = newstr;
					lastLeft = target + countleft;
					target = 0;
					output.push_back(str);
				}
				else {
					count --;
					countleft ++;
				}
			} 
		}
		return output;
    }
}; 
//111222 112122 112212 121122 121212 

int main() {
	Solution s;
	vector<string> out;
	out = s.generateParenthesis(3);
	for(int i = 0; i<out.size(); i++)
		cout<<out[i]<<endl;
	return 0;
}
