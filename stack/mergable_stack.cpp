#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
	int data;
	Node *next,*prev;
	Node(int x);
	Node(int x,Node *pr);
};

Node::Node(int x)
{
	data=x;
	next=prev=NULL;
}

Node::Node(int x,Node *pr)
{
	data=x;
	next=NULL;
	prev=pr;
}


class mergableStack
{
private:
	Node *head;
	Node *tail;
	int s;
public:
	mergableStack()
	{
		head=tail=NULL;
		s=0;
	}
	void push(int x);
	int pop();
	bool empty();
	int size();
	friend mergableStack merge(mergableStack s1,mergableStack s2);	
};

mergableStack merge(mergableStack s1,mergableStack s2)
{
	s1.tail->next = s2.head;
	s2.head->prev = s1.tail;
	mergableStack s3;
	s3.head = s1.head;
	s3.tail = s2.tail;
	s3.s = s1.s+s2.s;

	return s3;
}

int mergableStack::size()
{
	return s;
}

bool mergableStack::empty()
{
	if(s==0)
		return true;
	else 
		return false;
}

void mergableStack::push(int x)
{
	if(!head)
	{
		head = new Node(x);
		tail=head;
		s++;
	}
	else
	{
		tail->next = new Node(x,tail);
		s++;
		tail=tail->next;
	}
	//cout<<"inserted "<<tail->data<<endl;

}


int mergableStack::pop()
{
	if(head==NULL)
		return -1;
	else if(head==tail )
	{
		int temp=head->data;
		Node *tempN = head;
		head=tail=NULL;
		delete tempN;
		s--;
		return temp;
	}
	else
	{
		int temp=tail->data;
		Node * tempN = tail;
		tail = tail->prev;
		s--;
		tail->next=NULL;
		delete tempN;
		return temp;
	}


}

int main(int argc, char const *argv[])
{
	mergableStack s1,s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s2.push(5);
	s2.push(6);
	s2.push(7);
	s2.push(8);
	//cout<<(s1.pop());
	mergableStack s3 = merge(s1,s2);
	while(!s3.empty())
	{
		cout<<s3.pop()<<" ";
	} 
	return 0;
}