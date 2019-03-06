#include<iostream>
using namespace std;
typedef struct Node{
	int id;
	Node *next;
}Node;

int StrToInt(string str)
{
	int num=0, c=10;
	for(int i=0;i<str.length();i++)
	{
		if(i!=0)
			num*=c;
		num+=str[i]-'0';
	}
	return num;
}
bool check(Node *nl, int id)
{
	Node *p , *head;
	p=new Node();
	head=new Node();
	head =nl;
	p=nl;
	while(p->next!=NULL)
	{
		if(p->next->id==id)
		{
			Node *q;
			q =new Node();
			q=p->next;
			p->next=q->next;
			q->next=head->next;
			head->next=q;
			q->id=id;
			return true;
		}
		p=p->next;
	}
	return false;
}

int main()
{
	Node *nodelist[10], *head[10];
	int t=0, n, N, id, v;
	string str;
	for(t=0;t<10;t++)
	{
		nodelist[t] = new Node();
   		nodelist[t]->next=NULL;
		head[t] =new Node();//表头
		head[t]->next=NULL;
	}
    //初始化十个链表 
    cin>>n;//输入数据组数
	for(int i=0;i<n;i++)
	{
		cin>>N;
		
		nodelist[i]->next = head[i];
		Node *p;
		p=new Node();
		p->next =NULL;
		cin>>id;
		head[i]->id=id;
		v=N-1;
		head[i]->next =NULL;
		while(v--)
		{
			Node *p;
			bool c=false;
			p=new Node();
			p->next =NULL;
			cin>>id;//输入ID
			c=check(nodelist[i],id);
			if(c==false)//不存在，插入表头 
			{
				p->id =id;
				p->next=head[i]; 
				head[i]=p;
				nodelist[i]->next=p;
			}
	//		cout<<"nih "<<endl;
			
		}
			
	}
	for(int i=0;i<n;i++)
	{
	while(nodelist[i]->next!=NULL)
		{
			cout<<nodelist[i]->next->id;
			if(nodelist[i]->next->next!=NULL)
			cout<<" "; 
			
			nodelist[i]=nodelist[i]->next;
		}
		cout<<endl;
	}
	return 0;
}
