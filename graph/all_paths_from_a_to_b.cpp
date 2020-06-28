#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int V;
	list<int>  *adj;
	vector<bool> vis;
	Graph(int n){
		V = n;
		adj = new list<int> [V];
		vis = vector<bool> (V,false);
	}
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
	}

	int countPath(int s,int d)
	{
		vis[s]=true;
		if(s==d)
		{
			vis[s]=false;
			return 1;
		}
		int ans=0;
		for( auto it:adj[s])
			if(!vis[it])
				ans+=countPath(it,d);
		vis[s]=false;
		return ans;

	}
};

int main(int argc, char const *argv[])
{
	Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(1, 3); 
    g.addEdge(2, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 4); 
  
    int s = 0, d = 3; 
    cout << g.countPath(s, d);
	return 0;
}