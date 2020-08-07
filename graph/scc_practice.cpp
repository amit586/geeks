#include <bits/stdc++.h>
using namespace std;

void connComp(int v,vector<bool> &vis,vector<int> adj[],set<int> &scc){
	scc.insert(v);
	vis[v]=true;
	for(auto it:adj[v])
		if(!vis[it])
			connComp(it,vis,adj,scc);
}


void  fillStack(int v,vector<bool> &vis,stack<int> &s,vector<int> *adj)
{
	vis[v]=true;
	for(auto it:adj[v])
		if(!vis[it])
			fillStack(it,vis,s,adj);
	s.push(v);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		cout<<"Test case:"<<tc<<endl;
		int V,E,u,v;
		cin>>V>>E;
		vector<int> adj[V];
		vector<int> inv[V];
		for(int i=0;i<E;i++)	cin>>u>>v,adj[u].push_back(v),inv[v].push_back(u);
		stack<int> s;

		vector<bool> vis(V,false);
		vector<set<int>> components;
		for(int i=0;i<V;i++)
			if(!vis[i])
				fillStack(i,vis,s,adj);
		fill(vis.begin(), vis.end(),false);
		int temp;
		while(!s.empty())
		{
			temp = s.top();
			s.pop();
			if(!vis[temp])
			{
				set<int> scc;
				connComp(temp,vis,inv,scc);
				components.push_back(scc);
			}

		}

		for(int i=0;i<components.size();i++)
		{
			cout<<"scc ";
			for(auto it:components[i])
				cout<<it<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}