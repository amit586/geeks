#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next,*prev;
	Node(int x)
	{
		data=x;
		next=prev=NULL;
	}
	Node(int x,Node *pre)
	{
		data=x,prev = pre,next=NULL;
	}	
};

class Stack
{
	Node *head,*tail;
	int size;
public:
	Stack();
	void push(int x);
	void pop();
	int top();
	bool empty();
	void reverse();
};

void Stack::reverse()
{
	if(size <=1)
		return;

	Node *tempH = head;
	Node *p= tail;
	while(p)
	{

		swap(p->next,p->prev);
		p=p->next;
	}
	head = tail;
	tail = tempH;
}

void Stack::pop()
{
	if(empty())
		return;
	Node *tempN = tail;

	if(head==tail)
		head=NULL,tail=NULL;
	else
	{
		tail=tail->prev;
		tail->next=NULL;
	}
	size--;
	delete tempN;
}

int Stack::top()
{
	if(!empty())
		return tail->data;
	return -1;
}

bool Stack::empty()
{
	if(size==0)
		return true;
	return false;
}

void Stack::push(int x)
{
	if(head==NULL)
	{
		head = new Node(x);
		tail=head;
		size++;
		return;
	}
	else
	{
		size++;
		tail->next = new Node(x,tail);
		tail=tail->next;
	}
}

Stack::Stack()
{
	head=tail=NULL;
	size=0;
}

int main(int argc, char const *argv[])
{
	Stack s;
	int n;
	cin>>n;
	int temp;
	while(n--)
		cin>>temp,s.push(temp);
	s.reverse();
	
	while(!s.empty())
		cout<<s.top()<<" ",s.pop();
	return 0;
}