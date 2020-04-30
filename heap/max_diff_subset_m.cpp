#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		priority_queue <int,vector<int> ,greater<int>> mn(v.begin(),v.end());
		priority_queue<int> mx(v.begin(),v.end());
		int s=0;
		while(m)
			s+=mx.top()-mn.top(),mx.pop(),mn.pop(),m--;
		cout<<s<<endl;

	}
	return 0;
}