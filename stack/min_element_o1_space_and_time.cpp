#include <bits/stdc++.h>
using namespace std;

class MyStack
{
	stack <int> s;
	int minEle;
public:
	MyStack();
	void push(int x);
	void pop();
	void peek();
	void getMin();	
};

MyStack::MyStack()
{
	minEle=INT_MAX;
}

void MyStack::peek()
{
	if(s.empty())
	{
		cout<<"empty stack"<<endl;
		return ;
	}
	else
	{
		cout<<"peek "<<s.top()<<endl;
	}
}

void MyStack::getMin()
{
	cout<<"minimum element "<<minEle<<endl;
}

void MyStack::pop()
{
	if(s.empty())
	{
		cout<<"empty stack"<<endl;
		return ;
	}
	cout<<"popped "<<s.top()<<endl;
	if(s.top()>=minEle)
		s.pop();
	else
	{
		minEle = 2*minEle -s.top();
		s.pop();
	}
}

void MyStack::push(int x)
{
	if(s.empty())
	{
		minEle=x;
		s.push(x);
		cout<<"first element "<<x<<endl;
		return;
	}
	if(x<minEle)
	{
		s.push(2*x-minEle);
		minEle=x;
	}
	else
	{
		s.push(x);
	}
	cout<<"inserted "<<s.top()<<endl;
}

int main(int argc, char const *argv[])
{
	MyStack s; 
    s.push(3); 
    s.push(5); 
    s.getMin(); 
    s.push(2); 
    s.push(1); 
    s.getMin(); 
    s.pop(); 
    s.getMin(); 
    s.pop(); 
    s.peek(); 
  
    return 0; 
	return 0;
}