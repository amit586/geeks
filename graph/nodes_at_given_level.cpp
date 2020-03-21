#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int v);
	void addEdge(int v,int w);
	void BFSUtil(int root,int level,int &i);
	int BFS(int root,int level);
};

Graph::Graph(int v)
{
	V=v;
	adj = new list<int> [V];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::BFSUtil(int root,int level,int &i)
{
	if(level<=0)
	{
		cout<<root<<" ";
		i++;
		return;
	}
	else
	{
		for(auto it = adj[root].begin();it!=adj[root].end();++it)
		{
			BFSUtil(*it,level-1,i);
		}
	}
}

int Graph::BFS(int root,int level)
{
	int i=0;
	BFSUtil(root,level,i);
	cout<<endl;
	return i;
}

int main(int argc, char const *argv[])
{
	Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
  
    int level = 2; 
  
    cout << g.BFS(0, level); 
	return 0;
}