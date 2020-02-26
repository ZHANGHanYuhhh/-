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
	/*�ƶ���������ʼ��(((())))�����ս��ż��λ��Ϊ(,��()()()()��ÿ��ֻ�ƶ����һ��(���ƶ��������ڶ�λʱ�����������ַ���,
	���ɷ���Ϊ�������һλ(��ʼ��ǰ���������Ҽ�¼������(),����)��������1������(��1�����������ʱ������Ϊ0�������ǰ����
	���������(())()()�������ڶ���(�ļ�������ֵΪ0����ʾ�޷��ƶ���λ��������ǰ��ֱ���ҵ�һ��(���ڸ�λ�ļ�����ֵ����0����ʱ
	����λǰ�ַ�����������λ�滻Ϊ�������Ұ���֮ǰʣ�ࣨ�������������ַ����������ַ�������Ϊ��()((()))��֮������ƶ����һλ
	�ģ�,ֱ���ﵽ����״̬��	 
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
			//Ѱ��Ҫ���Ƶ�������
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
				else if(str[target]=='('&&count!=1&&!isEnd(str)) //��()()���� 
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
