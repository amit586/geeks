#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node *prev;
	Node(int x){data=x;next=prev=NULL;}
	Node(int x,Node *pre)
	{
		data=x;
		next=NULL;
		prev = pre;
	}	
};

class Dequeue
{
	Node *head,*tail;
	int s;
public:
	Dequeue();
	void push(int x);
	int pop();
	//void enqueue(int x);
	int dequeue();
	int size();
	bool empty(); 
};

int Dequeue::size()
{
	return s;
}

bool Dequeue::empty()
{
	if(s==0)
		return true;
	return false;
}

int Dequeue::dequeue()
{
	if(s==0)
	{
		cout<<"empty :"<<-1<<endl;
		return -1;
	}
	else if(s==1)
	{
		s--;
		Node *tempN = head;
		int temp = head->data;
		head=NULL;
		tail=NULL;
		delete tempN;
		cout<<"dequeue "<<temp<<endl;
		return temp;
	}
	else
	{
		s--;
		Node *tempH = head;
		int temp = head->data;
		head=head->next;
		head->prev=NULL;
		delete tempH;
		cout<<"dequeue "<<temp<<endl;
		return temp;

	}
}

// void Dequeue::enqueue(int x)
// {
// 	if(head==NULL)
// 	{
// 		s++;
// 		head = new Node(x);
// 		tail=head;
// 		cout<<"first enqueue "<<x<<endl;
// 	}
// 	else
// 	{
// 		Node *tempH = head;
// 		head = new Node(x);
// 		head->next = tempH;
// 		tempH->prev = head;
// 		cout<<"enqueue "<<x<<endl;
// 		s++;
// 	}
// }

int Dequeue::pop()
{
	if(head==NULL)
	{
		cout<<"empty stack :"<<-1<<endl;
		return -1;
	}
	else if(head==tail)
	{
		s--;
		Node *tempN = head;
		int temp = head->data;
		head=NULL;
		tail=NULL;
		delete tempN;
		cout<<"popped "<<temp<<endl;
		return temp;
	}
	else
	{
		s--;
		Node *tempN = tail;
		int temp = tail->data;
		tail=tail->prev;
		delete tempN;
		cout<<"popped "<<temp<<endl;
		return temp;
	}
	

}

void Dequeue::push(int x)
{
	if(head==NULL)
	{
		head = new Node(x);
		tail=head;
		cout<<"first push "<<x<<endl;
	}
	else
	{
		tail->next = new Node(x,tail);
		cout<<"push "<<x<<endl;
	}
	s++;
}

Dequeue::Dequeue()
{
	head=NULL;
	s=0;
}

int main(int argc, char const *argv[])
{
	Dequeue d;
	d.push(1);
	d.push(2);
	d.push(3);
	d.push(4);
	d.push(5);
	d.push(6);
	d.push(8);
	d.push(9);
	d.pop();
	d.dequeue();
	d.dequeue();
	d.dequeue();
	d.dequeue();
	d.dequeue();
	d.dequeue();
	d.dequeue();
	d.dequeue();
	d.dequeue();
	return 0;
}