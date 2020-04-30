#include <bits/stdc++.h>
using namespace std;

void sort_stack(stack<int> &s,int n)
{
	if(s.empty())
	{
		s.push(n);
		return;
	}
	int x=s.top();
	if(s.top()>n)
		s.pop(),sort_stack(s,n),s.push(x);
	else
		s.push(n);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		stack<int> s;
		int n;
		cin>>n;
		int temp;
		for(int i=0;i<n;i++)
			cin>>temp,sort_stack(s,temp);
		while(!s.empty())
			cout<<s.top()<<" ",s.pop();
	}
	return 0;
}