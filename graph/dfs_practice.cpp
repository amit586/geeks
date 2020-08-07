#include <bits/stdc++.h>
using namespace std;

void dfs(int v,vector<bool> &vis,vector<int> *adj){
	vis[v]=true;
	cout<<v<<" ";
	for(auto it:adj[v])
		if(!vis[it])
			dfs(it,vis,adj);
}

void bfs(int v,vector<bool> &vis,vector<int> *adj) {
	queue<int> s;
	s.push(v);
	int temp;
	while(!s.empty())
	{
		temp = s.front();
		s.pop();
		if(!vis[temp])
			cout<<temp<<" ";
		vis[temp]=true;
		for(auto it:adj[temp])
			if(!vis[it])
				s.push(it);
	}
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,e,u,v;
		cin>>n>>e;
		vector<int> adj[n];
		for(int i=0;i<e;i++)
			cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
		vector<bool> vis(n,false);
		for(int i=0;i<n;i++)
			if(!vis[i])
				dfs(i,vis,adj);
		cout<<endl;
		fill(vis.begin(),vis.end(),false);
		for(int i=0;i<n;i++)
			if(!vis[i])
				bfs(i,vis,adj);
		cout<<endl;

	}
	return 0;
}