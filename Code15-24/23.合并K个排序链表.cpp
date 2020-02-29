#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* out = new ListNode(NULL);
		ListNode *p = out;
		bool first = true;
        for(int i=0;i<lists.size();i++) {
            if(lists[i] == NULL) {
			    vector<ListNode*>::iterator it = lists.begin() + i;
			    lists.erase(it);
                i--;
		    }
        }
		if(lists.size() == 0) {
			return NULL;
		}
		while(lists.size()!=0) {
			//记录最小节点位置，将最小节点取出，加入到链表中，然后重新push进vector
			int position = 0;
			int min_point = lists[0]->val;
		//	cout<<"list+size"<<lists.size()<<endl;
			for(int i = 0; i<lists.size(); i++) {
				if(lists[i]->val < min_point)	{
					min_point = lists[i]->val;
					position = i;
			//		cout<<"val: "<<lists[i]->val<<" i: "<<i<<" minp: "<<min_point<<endl;
				}
			} 
		//	cout<<"val: "<<position<<" minp: "<<min_point<<endl;
			ListNode * temp = lists[position];
			if(first) {
				out->val = temp->val;
				p = out;
				first = false;
			}
			else {
				p->next = temp;
				p = temp;
			}
			temp = temp->next;
		//	ListNode *test = temp;
			// while(test!=NULL)
			// {
			// 	cout<<test->val <<" ";
			// 	test = test->next;
			// }
		//	cout<<endl;
			vector<ListNode*>::iterator it = lists.begin() + position;
			lists.erase(it);
			if(temp!=NULL)
				lists.push_back(temp);
		//	cout<<"sds: "<<lists[0]->val<<" size: "<<lists.size()<<endl;
		//	vector<ListNode*>::iterator it = lists.begin()+position;
    		if(lists.size()==1) {
    			ListNode * temp2 = lists[0];
    			p->next = temp2;
    			lists.pop_back();
			}
			
		}
		return out;
    }
};

int main() {
	Solution s;
	ListNode *a = new ListNode(1);
	ListNode *p1 = new ListNode(3);
	ListNode *p2 = new ListNode(4);
	ListNode *b = new ListNode(1);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *c = new ListNode(2);
	ListNode *p7 = new ListNode(6);
	a->next = p1;
	p1->next = p2;
	b->next = p4;
	p4->next = p5;
	c->next = p7;
	vector<ListNode*> z;
	z.push_back(a);
	z.push_back(b);
	z.push_back(c);
	ListNode *out = s.mergeKLists(z);
	while(out!=NULL)
	{
		cout<<out->val<<" "<<endl;
		out = out->next;
	 } 
	return 0;
}
