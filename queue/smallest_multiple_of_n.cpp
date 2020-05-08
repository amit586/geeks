#include <bits/stdc++.h>
using namespace std;

long long nextNum(queue<long long> &q)
{
	long long ans = q.front();
	q.pop();
	q.push(ans*10);
	q.push(ans*10+9);
	return ans;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		long long x=9;
		cin>>n;
		queue<long long > q;
		q.push(x);
		while(x%n!=0)
			x = nextNum(q);
		cout<<x<<endl;
	}
	return 0;
}