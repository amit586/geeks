#include <bits/stdc++.h>
using namespace std;


const int N=2e5+5;
int n,m;
vector<int> adj[N],T[N];
int vis[N];
stack<int> s;


void fillDfs(int i)
{
	vis[i]=true;
	for(auto it:adj[i])
		if(!vis[i])
			fillDfs(it);
	s.push(i);
}

void printDfs(int i)
{
	vis[i]=false;
	cout<<i<<" ";
	for(auto it:T[i])
		if(vis[it])
			printDfs(it);
}


void printScc()
{	
	memset(vis,0,n);
	for(int i=0;i<n;i++)
		if(!vis[i])
			fillDfs(i);
	for(int i=0;i<n;i++)
		for(auto it:adj[i])
			T[it].push_back(i);
	while(!s.empty())
	{
		if(vis[s.top()])
			printDfs(s.top()),s.pop(),cout<<endl;
		else if(!vis[s.top()])
			s.pop();
	}
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int u,v;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			adj[i].clear(),T[i].clear();
		
		for(int i=0;i<m;i++)
			cin>>u>>v,adj[v].push_back(u);

		printScc();
	}
	return 0;
}