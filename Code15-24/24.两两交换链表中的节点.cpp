#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode *p = head;
	if(head == NULL ||head->next==NULL)
		return p;
	struct ListNode *q = head->next;
	p->next = q->next;
	q->next = p;
	head = q;
	while(p!=NULL&&q!=NULL) {
		if(p->next==NULL||p->next->next==NULL)
			break;
		struct ListNode *temp = p;	
		q = p->next->next;
		p=p->next;
		p->next = q->next;
		q->next = p;
		temp->next = q;

	}
	return head;
}
int main() {

	struct ListNode *head = new struct ListNode();
	struct ListNode *p1 = new struct ListNode();
	struct ListNode *p2 = new struct ListNode();
	struct ListNode *p3 = new struct ListNode();
	p1->val = 2;
	p2->val = 3;
	p3->val = 4;
	head->val = 1;
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	struct ListNode *out =	swapPairs(head);
	while(out!=NULL) {
		cout<<out->val<<" ";
		out = out->next;
	}
	return 0;
} 
