#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list <int> *adj;
public:
	Graph(int V);
	void addEdge(int ,int);
	void DFSUntil(int v,vector <bool> &vis);
	int findMother();
};

Graph::Graph(int v)
{
	V = v;
	adj =new list <int> [V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUntil(int v,vector <bool> &vis)
{
	vis[v]=true;
	for(auto it=adj[v].begin();it!=adj[v].end();++it)
		if(!vis[*it])
			DFSUntil(*it,vis);
}

int Graph::findMother()
{
	vector <bool> vis(V,false);
	int motherV = 0;
	
	for(int i=0;i<V;i++)
	{
		if(!vis[i])
		{
			DFSUntil(i,vis);
			motherV = i;
			//cout<<"mother vertex : "<<motherV<<endl;
		}
	}

	fill(vis.begin(),vis.end(),false);

	DFSUntil(motherV,vis);
	
	for(int i=0;i<V;i++)
		if(!vis[i])
			motherV=-1;

	return motherV;
}

int main(int argc, char const *argv[])
{
	Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
  
    cout << "A mother vertex is " << g.findMother(); 
  
	return 0;
}