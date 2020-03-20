#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	unordered_set <int> *adj;
public:
	Graph(int v);
	void addEdge(int v,int w);
	bool findNode(int v,int w);	
};

Graph::Graph(int V)
{
	this->V=V;
	adj = new unordered_set<int>[V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].insert(w);
	adj[w].insert(v);
}

bool Graph::findNode(int v,int w)
{
	auto it=adj[v].find(w);
	if(it!=adj[v].end())
		return true;
	return false;
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
    cout<<g.findNode(0,1); 

	return 0;
}