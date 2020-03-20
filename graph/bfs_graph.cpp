#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUntil(int v,bool vis[]);
public:
	Graph(int V);
	void addEdge(int v,int w);
	void DFS(int v);
	
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int> [V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUntil(int v,bool vis[])
{
	cout<<v<<" ";
	vis[v]=true;
	list <int>::iterator i;
	for(i = adj[v].begin();i!=adj[v].end();++i)
		if(!vis[*i])
			DFSUntil(*i,vis);
}


void Graph::DFS(int v)
{
	//bool *vis = new bool[V];
	bool vis[V];
	for(int i=0;i<V;i++)
		vis[i]=false;
	
	// works for even disconnected graph ///////////////
	for(int i=0;i<V;i++)
		DFSUntil(v,vis); 
}

int main(int argc, char const *argv[])
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 

	return 0;
}