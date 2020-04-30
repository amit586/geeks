#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next ,*prev;
	Node(int x)
	{
		data=x;
		prev=next=NULL;
	}
};

class Stack
{
	Node *head;
	Node *tail;
	int s;
	int min;
public:
	Stack();
	void push(int x);
	void pop();
	void getEnd();
	void popEnd();
	void getMin();
	
};

void Stack::getMin()
{
	cout<<"min element "<<min<<endl;
}

void Stack::popEnd()
{
	if(head==NULL)
	{
		cout<<"empty stack "<<endl;
		return;
	}
	else if(s==1)
	{
		Node *temp  = head;
		head=NULL;
		tail=NULL;
		s--;
		min = INT_MAX;
		cout<<"end deleted "<<temp->data<<endl;
		delete temp;
	}
	else
	{
		Node *temp = head;
		head = head->next;
		head->prev = NULL;
		cout<<"end deleted "<<temp->data<<endl;
		if(temp->data<min)
		{
			min = 2*min-temp->data;
		}
		delete temp;
	}
}

void Stack::getEnd()
{
	if(head==NULL)
	{
		cout<<"empty stack "<<endl;
		return ;
	}
	else
	{
		cout<<"end "<<head->data<<endl;
		return ;
	}
}

void Stack::pop()
{
	if(head==NULL)
	{
		cout<<"empty stack "<<endl;
		return;
	}
	else if(s==1)
	{
		s=0;
		Node *temp = head;
		cout<<"popped "<<temp->data;
		delete temp;
		min = INT_MAX;
		head=NULL;
		tail=NULL;
	}
	{
		if(tail->data > min)
		{
			s--;
			cout<<"popped "<<tail->data<<endl;
			Node *temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
		}
		else
		{
			s--;
			cout<<"popped "<<tail->data<<endl;
			min = 2*min - tail->data;
			Node *temp = tail;
			tail = tail->prev;
			tail->next = NULL;
		}

	}
}

void Stack::push(int x)
{
	if(head==NULL)
	{
		head=new Node(x);
		tail=head;
		s++;
		min = x;
	}
	else
	{
		Node *temp;
		if(x>=min)
			 temp= new Node(x);
		else
		{
			temp = new Node(2*x-min);
			min =x;
		}
		temp->prev=tail;
		tail->next=temp;
		tail=tail->next;
		s++;
	}

	cout<<"pushed "<<x<<endl;
}

Stack::Stack()
{
	s=0;
	head=tail=NULL;
}

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.pop();
	s.getMin();
	s.popEnd();
	s.popEnd();
	return 0;
}