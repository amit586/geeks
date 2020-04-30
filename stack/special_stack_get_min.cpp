#include <bits/stdc++.h>
using namespace std;

class specialStack
{
private:
	stack<int> s1;
	stack<int> mn;
	int size;
public:
	specialStack(int n);
	int top();
	void pop();
	void push(int x);
	int getMin();
	bool empty();
	bool isFull();

};

specialStack::specialStack(int n)
{
	size = n;
}

bool specialStack::empty()
{
	return s1.empty();
}

int specialStack::getMin()
{
	return mn.top();
}


void specialStack::pop()
{
	if(!s1.empty())
	{
		s1.pop();
		mn.pop();
	}
}

void specialStack::push(int x)
{
		s1.push(x);
		if(mn.empty())
			mn.push(x);
		else if(x<mn.top())
			mn.push(x);
		else
			mn.push(mn.top());
}

int specialStack::top()
{
	return s1.top();
}

bool specialStack::isFull()
{
	if(s1.size()==size)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	specialStack s(10);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(0);
	s.push(5);
	cout<<s.getMin()<<endl;
	s.pop();
	s.pop();
	s.pop();
	cout<<s.getMin()<<endl;


	return 0;
}