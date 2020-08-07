#include <bits/stdc++.h>
using namespace std;

int tropSort(int v,vector<bool> &vis,vector<int> *adj,int index,vector<int> &order)
{
	vis[v]=true;
	for(auto it:adj[v])
		if(!vis[it])
			index = tropSort(it,vis,adj,index,order);
	order[index] = v;
	// cout<<v<<" "; 
	return index-1;
}

void khans(vector<int> *adj,int n)
{
	vector<int> in(n);
	queue<int> q;
	for(int i=0;i<n;i++)
		for(auto it:adj[i])
			in[it]++;

	for(int i=0;i<n;i++)
		if(in[i]==0)
			q.push(i);
	vector<int> sorted(n);
	int index = 0;
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		sorted[index++]=temp;
		for(auto it:adj[temp])
		{
			in[it]--;
			if(in[it]==0)
				q.push(it);
		}
	}
	cout<<"khans: ";
	for(int i=0;i<n;i++)
		cout<<sorted[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int e,n,u,v;
		cin>>e>>n;
		vector<int> adj[n];
		for(int i=0;i<e;i++)
			cin>>u>>v,adj[u].push_back(v);

		vector<bool> vis(n,false);
		vector<int> order(n);
		int index = n-1;
		for(int i=0;i<n;i++)
			if(!vis[i])
				index = tropSort(i,vis,adj,index,order);
		// cout<<endl;
		for(int i=0;i<n;i++)
			cout<<order[i]<<" ";
		cout<<endl;

		// khans algorithm //////////
		khans(adj,n);
	}
	return 0;
}