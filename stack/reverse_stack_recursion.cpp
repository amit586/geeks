#include <bits/stdc++.h>
using namespace std;

class Stack
{
	stack <int> s;
public:
	void push(int x);
	void pop();
	bool empty();
	int top();	
};

void Stack::push(int x)
{
	if(s.empty())
	{
		s.push(x);
	}
	else
	{
		int temp = s.top();
		s.pop();
		push(x);
		s.push(temp);
	}
}

bool Stack::empty()
{
	return s.empty();
}

int Stack::top()
{
	if(!s.empty())
		return s.top();
}

void Stack::pop()
{
	if(!s.empty())
		s.pop();
}

int main(int argc, char const *argv[])
{
	Stack  s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	//reverse(s);
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}