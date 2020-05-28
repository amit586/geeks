#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> *g,int i,vector<bool>&vis)
{
	if(!vis[i])
	{
		vis[i]=true;
		bool ans = true;
		for(int j=0;j<g[i].size();j++)
			if(!vis[g[i][j]])
				ans=ans&&dfs(g,g[i][j],vis);
			else
				{ans=false;break;}
		return ans;
	}
	else
		return false;
}


int main(int argc, char const *argv[])
{
	int V,n;
	cin>>V>>n;
	vector<int> g[V];
	while(n--)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}

	vector<bool> vis(V,false);
	bool ans=true;
	for(int i=0;i<V;i++)
	{
		ans=ans&&dfs(g,0,vis);
		fill(vis.begin(),vis.end(),false);
	}
	cout<<ans<<endl;

	return 0;
}