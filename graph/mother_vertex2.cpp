#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m;
std::vector<int> adj[N];
bool vis[N];

bool checVis()
{
	for(int i=0;i<n;i++)
		if(!vis[i])
			return false;
	return true;
}

void dfs(int i)
{
	vis[i]=true;
	for(auto it:adj[i])
		if(!vis[it])
			dfs(it);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		cin>>n>>m;
		int u,v;
		for(int i=0;i<n;i++)
			adj[i].clear();
		
		for(int i=0;i<m;i++)
			cin>>u>>v,adj[u].push_back(v);

		memset(vis,0,n);
		int last = 0;
		for(int i=0;i<n;i++)
			if(!vis[i])
				dfs(i),last=i;
		memset(vis,0,n);
		dfs(last);
		//cout<<last<<endl;
		checVis()?cout<<last<<endl:cout<<-1<<endl;
	}
	return 0;
}