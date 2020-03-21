#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void countPathUtil(int v,int e,int &i,vector <bool> &vis);

public:
	Graph(int v);
	void addEdge(int v,int w);
	int countPath(int v,int e);
};

Graph::Graph(int v)
{
	V = v;
	adj = new list<int> [V];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::countPathUtil(int v,int e,int &i,vector <bool> &vis)
{
	vis[v]=true;

	if(v==e)
	{
		++i;
	}
	else 
	{
		
		for(auto it = adj[v].begin();it!=adj[v].end();++it)
			if(!vis[*it])
				countPathUtil(*it,e,i,vis);
	}
	
	vis[v]=false;
}

int Graph::countPath(int v,int e)
{
	vector<bool> vis(V,false);
	int i=0;
	countPathUtil(v,e,i,vis);
	return i;

}

int main(int argc, char const *argv[])
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 
  
    int s = 2, d = 3; 
    cout << g.countPath(s, d); 
  
	return 0;
}