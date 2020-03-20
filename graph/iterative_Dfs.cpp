#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list <int> *adj;
public:
	Graph(int v);
	void addEdge(int v,int w);
	void DFS(int v);
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

void Graph::DFS(int v)
{
	stack <int> s;
	vector<bool> vis(V,false);
	s.push(v);
	vis[v]=true;
	while(!s.empty())
	{

		int temp = s.top();
		cout<<temp<<" ";
		s.pop();
		for(auto it =adj[temp].begin();it!=adj[temp].end();++it )
		{
			if(!vis[*it])
			{
				vis[*it]=true;
				s.push(*it);
			}
		}
		
	}
}

int main(int argc, char const *argv[])
{
	Graph g(5); // Total 5 vertices in graph 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4);
    g.DFS(0); 
	return 0;
}