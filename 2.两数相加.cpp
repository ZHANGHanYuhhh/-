#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = new ListNode(0);
		ListNode *l = p;
        int ans, c = 0;//本位和和进位
        ans = l1->val+l2->val;
        if(ans>=10)
        {
        	ans = ans - 10;
        	c = 1;
		}
		p->val = ans;
		l1 = l1->next;
		l2 = l2->next;
		while(l1!=NULL&&l2!=NULL)
		{
			ListNode *q = new ListNode(0);
			ans = l1->val+l2->val+c;
	        if(ans>=10)
	        {
	        	ans = ans - 10;
	        	c = 1;
			}
			else
			{
				c =0;
			}
			q->val = ans;
			p->next = q;
			p = p->next;
			l1 = l1->next;
			l2 = l2->next;
		}
        while(l1!=NULL)//第二个数位数小
		{
			ans = l1->val +c;
			if(ans>=10)
	        {
	        	ans = ans - 10;
	        	c = 1;
			}
			else
			{
				c =0;
			}
			l1->val = ans;
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		} 
		while(l2!=NULL)//第一个数位数小
		{
			ans = l2->val +c;
			if(ans>=10)
	        {
	        	ans = ans - 10;
	        	c = 1;
			}
			else
			{
				c =0;
			}
			l2->val = ans;
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		} 
		if(c == 1)//最后有进位
		{
			ListNode *q = new ListNode(1);
			p->next = q; 
		} 
		return l;
    }
};

int main(){
	int alength, blength;
	Solution s;
	int temp;
	cin>>alength>>blength;
	cout<<endl<<"请输入数字a的逆序各位"<<endl;
	cin>>temp;
	ListNode *a =new ListNode(temp);
	a->next =NULL;
	ListNode *heada = a;
	for(int i=0;i<alength-1;i++)
	{
		cin>>temp;
		ListNode *b =new ListNode(temp);
		a->next = b;
		a = a->next;
	}
	cout<<endl<<"请输入数字b的逆序各位"<<endl;
	cin>>temp;
	ListNode *c =new ListNode(temp);
	ListNode *headb = c;
	for(int i=0;i<blength-1;i++)
	{
		cin>>temp;
			ListNode *d =new ListNode(temp);
		c->next = d;
		c = c->next;
	}
	ListNode *answer = s.addTwoNumbers(heada,headb);
	while(answer->next!=NULL)
	{
		cout<<answer->val<<"->";
		answer = answer->next;
	}
	cout<<answer->val<<endl;
	return 0;
}
