#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,v;
		cin>>n>>v;
		std::vector<int> adj[n];
		int x,y;
		while(v--)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);

		}

		for(int i=0;i<n;i++)
		{
			cout<<i;
			for(auto it = adj[i].begin();it!=adj[i].end();++it)
			{
				cout<<"->"<<*it;
			}
			cout<<endl;
		}
	
	}
	return 0;
}