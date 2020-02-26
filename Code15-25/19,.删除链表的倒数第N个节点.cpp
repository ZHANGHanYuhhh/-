#include<iostream>

/**
 * Definition for singly-linked list.
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p = head;
		ListNode *target = head;
		target = head;
		ListNode *rear = head;
		target = head;
		int count =1;
		while(rear->next!=NULL) {
			rear = rear->next;
           // cout<<"n: "<<count<<endl;
           // cout<<rear->val<<endl;
          //  cout<<target->val<<endl;
			if(count<=n)
				count ++;
			else if(count >n)
				target = target->next;
		}
		if(count>n&&n!=1)
        {
            target->next = target->next->next;
            //cout<<"dd "<<target->val;
        }
		else if(count>n&&n==1)
			target->next = NULL;
		else if(count==n&&n!=1)
        {
            
            p = p->next; 
            p->next = target->next->next;
        }
		else if(count==n&&n==1)
			return NULL;
		return p;
    }
};

int main() {
	
	return 0;
}
