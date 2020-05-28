#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;

bool check(int i,vector<int> g[],vector<bool> &vis,int &visCount,int parent)
{
	vis[i]=true;
	visCount++;
	for(auto it:g[i])
	{
		if(!vis[it])
		{
			if(!check(it,g,vis,visCount,i))
				return false;
		}
		else if(vis[it] && it!=parent)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int V,E;
		cin>>V>>E;
		vector<int> g[V];
		int x,y;
		for(int i=0;i<E;i++)
		{
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		vector<bool> vis(V,false);
		int visCount=0;
		bool ans = check(0,g,vis,visCount,-1);
		if(visCount==V && ans)
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
	}
	
	return 0;
}