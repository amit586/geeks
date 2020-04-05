#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int> *adj;
public:
	Graph(int v);
	void addEdge(int v,int w);
	void DFSUtil(int v,vector <bool> &vis);
	void DFS();
	void printKCores(int k);	
};

Graph::Graph(int v)
{
	V = v;
	adj=list<int> [V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::

int main(int argc, char const *argv[])
{
	int k = 3; 
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.printKCores(k); 
  
    cout << endl << endl; 
  
    Graph g2(13); 
    g2.addEdge(0, 1); 
    g2.addEdge(0, 2); 
    g2.addEdge(0, 3); 
    g2.addEdge(1, 4); 
    g2.addEdge(1, 5); 
    g2.addEdge(1, 6); 
    g2.addEdge(2, 7); 
    g2.addEdge(2, 8); 
    g2.addEdge(2, 9); 
    g2.addEdge(3, 10); 
    g2.addEdge(3, 11); 
    g2.addEdge(3, 12); 
    g2.printKCores(k); 
	return 0;
}