#include <bits/stdc++.h>
using namespace std;

class Stack
{
	priority_queue<pair<int,int>> pq;
	int count;
public:
	Stack();
	void push(int x);	
	void pop();
	int top();
	bool empty();
	int size();
};

int Stack::size()
{
	return pq.size();
}

bool Stack::empty()
{
	return pq.empty();
}

int Stack::top()
{
	if(pq.empty())
	{
		cout<<"empty "<<endl;
		return -1;
	}
	cout<<"top "<<pq.top().second<<endl;
}

void Stack::pop()
{
	if(pq.empty())
		return ;
	cout<<"popped "<<pq.top().second<<endl;
	pq.pop();
	count--;
}

void Stack::push(int x)
{
	cout<<"pushed "<<x<<endl;
	pq.push({++count,x});
}

Stack::Stack()
{
	count=0;
}

int main(int argc, char const *argv[])
{
	Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
    while(!s.empty()){ 
        //cout<<s.top()<<endl; 
        s.pop();
    }
	return 0;
}