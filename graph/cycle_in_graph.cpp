#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int v,vector<bool> &vis,int parent,std::vector<int> *adj){
	vis[v]=true;
	bool ans = false;
	for(auto it:adj[v])
	{
		if(vis[it] && it!=parent)
			return true;
		else if(!vis[v])
		{
			bool ans = detectCycle(it,vis,v,adj);
			if(ans)
				return true;
		}
		
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int u,v,e,n;
		cin>>n>>e;
		vector<int> adj[n];
		for(int i=0;i<n;i++)
			cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
		vector<bool> vis(n,false);
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
				bool flag = detectCycle(i,vis,-1,adj);
			if(flag)
					break;
		}
		cout<<flag<<endl;

		// detect cycle in undirected graph////
		
	}
	return 0;
}