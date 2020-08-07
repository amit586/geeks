#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int mindist(vector<bool> &stpSet,vector<int> &dist,int V)
{
	int mn_index,mn=INT_MAX;

	for(int v=0;v<V;v++)
		if(!stpSet[v] and dist[v]<=mn)
			mn=dist[v] ,mn_index = v;
	return mn_index;
}

void dijkstra(vector<vector<int>> &adj,int V,int src)
{
	vector<bool> stpSet(V,false);
	vector<int> dist(V,INT_MAX);

	dist[src]=0;
	int u;
	for(int v=0;v<V-1;v++)
	{
		u = mindist(stpSet,dist,V);
		stpSet[u] =true;
		for(int i=0;i<V;i++)
			if(adj[u][i] && !stpSet[i] && dist[u]!=INT_MAX  && dist[u]+adj[u][i]<dist[i])
				dist[i]=dist[u]+adj[u][i];
	}

	for(int i = 0;i<V;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
}

void dijkstraSTL(vector<vector<pair<int,int>>> &adj,int V,int src){
	set<pair<int,int> > pq;
	vector<int> dist(V,INT_MAX);
	pq.insert(make_pair(0,src));
	pair<int,int> temp;

	dist[src]=0;

	while(!pq.empty())
	{
		temp  = *(pq.begin());
		pq.erase(*(pq.begin()));
		int u = temp.s;

		for(auto it:adj[u])
		{
			int v = it.f;
			int w = it.s;
			if(dist[u]+w<dist[v])
			{
				if(dist[v]!=INT_MAX)
					pq.erase(make_pair(dist[v],v));
				dist[v] = dist[u]+w;
				pq.insert(make_pair(dist[v],v));
			}
		}
	}
	for(int i=0;i<V;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		// int n,src;
		// cin>>n;
		// vector<vector<int>> adj(n,vector<int> (n));
		// for(int i=0;i<n;i++)
		// 	for(int j = 0;j<n;j++)
		// 		cin>>adj[i][j];
		// cin>>src;
		//dijkstra(adj,n,src);

		int n,e,u,v,w,src;
		cin>>n>>e;
		vector<vector<pair<int,int>>>  adj(n);
		for(int i=0;i<e;i++)
			cin>>u>>v>>w,adj[u].push_back(make_pair(v,w)),adj[v].push_back(make_pair(u,w));
		cin>>src;
		dijkstraSTL(adj,n,src);
	}
	return 0;
}