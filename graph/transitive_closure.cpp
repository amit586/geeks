#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list <int> *adj;
public:
	vector <bool> *tClosure;	
	Graph(int v);
	void addEdge(int ,int);
	void DFSutil(int v,vector <bool> &vis,int i);
	void transitiveClosure();	
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int> [V];
	tClosure = new vector < bool> [V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			tClosure[i].push_back(false);
	} 
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFSutil(int v,vector <bool> &vis, int i)
{
	vis[v]=true;
	tClosure[i][v]=true;
	for(auto it=adj[v].begin();it!= adj[v].end();++it)
		if(!vis[*it])
			DFSutil(*it,vis,i);
}


void Graph::transitiveClosure()
{
	vector <bool > vis(V);
	for(int i=0;i<V;i++)
	{
		fill(vis.begin(),vis.end(),false);
		DFSutil(i,vis,i);
	}

	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			cout<<tClosure[i][j]<<" ";
		cout<<endl;
	}
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
  
    cout << "Transitive closure matrix is \n"; 
    g.transitiveClosure(); 	
	return 0;
}