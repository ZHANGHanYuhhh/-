#include<iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)//����ֱ�ӷ��ز��ǻ��Ĵ� 
        	return false;
        //��תһ�����֣�������תΪ�ַ���
        if(x<10)//С��10�������ǻ��Ĵ� 
        	return true;
        if(x%10 == 0)//�����ܱ�10�����Ķ����ǻ��Ĵ� 
        	return false;
		int halfnum = 0;
		int singel = 0;
		while(x>halfnum)//�ؼ�����xС�ڻ����halfnumʱ����ת��һ����� 
		{
			singel = x%10;
			halfnum *= 10;
			halfnum += singel; 
			x /= 10;
		} 
		if(x == halfnum||x*10+singel == halfnum)
			return true;
		else 
			return false;
    }
};

int main(){
	int n;
	int out;
	Solution s;
	while(cin>>n){
		out = s.isPalindrome(n);
		cout<<out<<endl;
	}
	return 0;
}
