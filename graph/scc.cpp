#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	
public:
	stack<int> s;
	void DFSUntill(int v,bool vis[], stack <int> &s,bool flag);
	Graph(int v);
	void addEdge(int v,int w);
	void DFS(bool flag);
	Graph transpose();
	void printScc();
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

void Graph::DFSUntill(int v, bool vis[],stack <int> &s,bool flag)
{
	cout<<v<<" ";
	vis[v]=true;
	for(auto it = adj[v].begin();it!=adj[v].end();++it)
		if(!vis[*it])
			DFSUntill(*it,vis,s,flag);
	
	if(flag)
		s.push(v);
}

void Graph::DFS(bool flag)
{
	bool vis[V];
	memset(vis,0,sizeof(vis));
	for(int i=0;i<V;i++)
	{	if(!vis[i])
		{	cout<<i<<" -> ";
			DFSUntill(i,vis,s,flag);
			cout<<endl;
		}
	}
	//cout<<s.size()<<endl;
	// while(!s.empty())
	// {
	// 	cout<<s.top()<<" ";
	// 	s.pop();
	// }
	// cout<<endl;
}

Graph Graph::transpose()
{
	Graph gt(V);
	for(int i=0;i<V;i++)
	{
		for(auto it = adj[i].begin();it!=adj[i].end();++it)
		{
			gt.addEdge(*it,i);
		}
	}
	return gt;
}


void Graph::printScc()
{
	DFS(true);
	Graph gt = transpose();
	stack <int> s2;
	bool visited[V];
	memset(visited,0,sizeof(visited));
	while(!s.empty())
	{
		if(!visited[s.top()])
		{
			gt.DFSUntill(s.top(),visited,s2,false);
			cout<<endl;
		}
		s.pop();
	}
}

int main()
{
	Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 

    Graph gt = g.transpose();
  	// Graph gt(5);
  	// gt.addEdge(0,1); 
   //  gt.addEdge(2,0); 
   //  gt.addEdge(1,2); 
   //  gt.addEdge(3,0); 
   //  gt.addEdge(4,3); 

    cout << "Following are strongly connected components in "
            "given graph \n"; 
    //g.DFS(true); 
    //gt.DFS(false);
    g.printScc();
	return 0;
}