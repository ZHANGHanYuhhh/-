#include<iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)//负数直接返回不是回文串 
        	return false;
        //反转一半数字，而不是转为字符串
        if(x<10)//小于10的数都是回文串 
        	return true;
        if(x%10 == 0)//所有能被10整除的都不是回文串 
        	return false;
		int halfnum = 0;
		int singel = 0;
		while(x>halfnum)//关键：当x小于或等于halfnum时，反转了一半的数 
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
