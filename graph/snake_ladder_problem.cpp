#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<int> adj[])
{
	set<pair<int,int>> pq;
	vector<int> dist(31,INT_MAX);
	bool vis[31]= {false};
	pq.insert({0,1});
	dist[1]=0;

	while(!pq.empty())
	{
		pair<int,int>  tmp = *pq.begin();
		pq.erase(*pq.begin());
		int u=tmp.second;
		vis[u]=true;
		if(u==30)
			break;
		for(auto v:adj[u])
		{
			if(dist[u]+1<dist[v])
			{
				if(dist[v]!=INT_MAX)
					pq.erase({dist[v],v});
				dist[v] = dist[u]+1;
				//cout<<v<<" :dist "<<dist[v]<<endl;
				pq.insert({dist[v],v});
			}
		}

	}
	// for(int i=0;i<=30;i++)
	// 	cout<<dist[i]<<" ";
	// cout<<endl;


	return dist[30];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{

		int n,u,v;
		cin>>n;
		vector<int> adj[31];
		for(int i=0;i<n;i++)
		{
			cin>>u>>v;
			for(int j=u-1;j>=max(1,u-6);j--)
				adj[j].push_back(v);
		}
		for(int i=1;i<=30;i++)
			for(int j=i+1;j<=min(i+6,30);j++)
				adj[i].push_back(j);

		

		// for(int i=1;i<=30;i++)
		// {
		// 	cout<<i<<": ";
		// 	for(auto it:adj[i])
		// 		cout<<it<<" ";
		// 	cout<<endl;
		// }

		cout<<dijkstra(adj)<<endl;
	}
	return 0;
}