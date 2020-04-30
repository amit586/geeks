#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *prev;
	Node *next;
	Node(int x)
	{
		data=x;
		prev=NULL;
		next=NULL;
	}
	Node(int x,Node *p)
	{
		data=x;
		prev=p;
		next=NULL;
	}
};

class middleStack
{
	Node *head;
	Node *tail;
	Node *mid;
	int size;
public:
	middleStack();
	void push(int x);
	int pop();
	int middle();
	void popMiddle();
};

middleStack::middleStack()
{
	head=NULL;
	tail=NULL;
	mid=NULL;
	size=0;
}

void middleStack::push(int x)
{
	size++;
	if(head==NULL)
	{	
		head = new Node(x);
		tail = head;
		mid = head;
	}
	else
	{	

		tail->next = new Node(x,tail);
		tail=tail->next;
		if(size%2)
			mid=mid->next;
	}
}

int middleStack::pop()
{
	if(head==NULL)
		return -1;
	else
	{
		int temp = tail->data;
		Node* tempN = tail;
		tail = tail->prev;
		tail->next=NULL;
		delete tempN;
		size--;
		if(size%2)
			mid=mid->prev;
		return temp;
	}
}

int middleStack::middle()
{
	if(mid==NULL)
		return -1;
	else
		return mid->data;
}

void middleStack::popMiddle()
{
	Node *tempN = mid;
	size--;
	mid->prev->next=mid->next;
	mid->next->prev = mid->prev;
	if(size%2==0)
		mid=mid->next;
	else
		mid=mid->prev;
	delete tempN;
}
int main(int argc, char const *argv[])
{
	middleStack s;
	s.push(1);
	s.push(2);
	cout<<s.middle()<<endl;
	s.push(3);
	s.push(4);
	cout<<s.middle()<<endl;
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	cout<<s.middle()<<endl;
	s.popMiddle();
	s.popMiddle();
	cout<<s.middle()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.middle()<<endl;
	return 0;
}