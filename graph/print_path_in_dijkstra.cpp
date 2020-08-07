#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src,vector<pair<int,int>> *adj,int V)
{
	set<pair<int,int>> pq;
	vector<int> parent(V,-1);

	vector<int> dist(V,INT_MAX);
	vector<bool> vis(V,false);
	pq.insert(make_pair(0,src));
	dist[src]=0,parent[src]=-1;

	while(!pq.empty())
	{
		
		pair<int,int> tmp = *(pq.begin());
		int u = tmp.second;
		pq.erase(tmp);
		vis[u]=true;

		for(auto it:adj[u])
		{
			int v,d;
			v = it.first,d = it.second;
			if(!vis[v] and dist[u]+d<dist[v])
			{
				if(dist[v]!=INT_MAX)
					pq.erase(make_pair(dist[v],v));
				dist[v]= d +dist[u];
				pq.insert(make_pair(dist[u]+d,v));
				parent[v]=u;
			}

		}

	}

	for(int i=0;i<V;i++)
	{
		int j = i;
		cout<<"path from "<<j<<" to "<<src<<" : ";
		while(parent[j]!=-1)
			cout<<j<<" ",j = parent[j];
		cout<<" dist: "<<dist[i]<<endl;

	}
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int V,E,u,v,w;
		cin>>V>>E;
		vector<pair<int,int>> adj[V];
		for(int i=0;i<E;i++)
			cin>>u>>v>>w,adj[u].push_back(make_pair(v,w));
		cin>>u;
		dijkstra(u,adj,V);
	}
	return 0;
}