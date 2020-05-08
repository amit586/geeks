#include <bits/stdc++.h>
using namespace std;

string nextBinary(queue<string> &q)
{
	string ans = q.front();
	q.pop();
	q.push(ans+"0");
	q.push(ans+"1");
	return ans;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		queue<string> q;
		q.push("1");
		for(int i=1;i<=n;i++)
		{
			cout<<nextBinary(q)<<endl;
		}
	}
	return 0;
}