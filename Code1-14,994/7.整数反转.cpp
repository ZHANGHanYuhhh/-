#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long num=0;
        int re=0;
        if(x<0)
        {
        	if(x==-2147483648)//�ų�����ֵ 
        		return 0;
        	re = 0 - x;//�Ѹ���ת��Ϊ���� 
        	int temp = re%10;
			num += temp;
			int single = re/10;
			while(single!=0)
			{
				temp = single%10;
				num *= 10;
				num += temp;
				single = single/10;
			}
			num =0-num; 
		}
		else
		{
			int temp = x%10;
			num += temp;
			int single = x/10;
			while(single!=0)
			{
				temp = single%10;
				num *= 10;
				num += temp;
				single = single/10;
			}
		}
		
		//�ж��Ƿ�Խ��
		int ans = num;
	//	cout<<"num: "<<num<<"  ans:"<<ans<<endl;
		if(ans!=num)
			return 0;
		return ans; 
    }
};

int main()
{
	Solution s;
	int a, b;
	while(cin>>a)
	{
		b = s.reverse(a);
		cout<<b<<endl;
	}
	return 0;
}
