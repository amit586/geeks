#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int V;
	set<int> *adj;
	Graph(int n){
		V = n;
		adj = new set<int>[V];
	}	

	void addEdge(int u,int v)
	{
		adj[u].insert(v);
		adj[v].insert(u);
	}

	void kCores(int k)
	{
		bool flag=true;
		while(flag)
		{
			flag=false;
			for(int i=0;i<V;i++)
				if(adj[i].size()<k and adj[i].size()!=0)
				{
					flag=true;
					for(auto it:adj[i])
						adj[it].erase(i);
					adj[i].clear();
				}
		}
	}

	void print()
	{
		for(int i=0;i<V;i++)
		{
			if(adj[i].size()==0)
				continue;
			cout<<i<<"-> ";
			for(auto it:adj[i])
				cout<<it<<" ";
			cout<<endl;
		}
	}
};

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
    g1.kCores(k); 
    g1.print();  
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
    g2.kCores(k);
    g2.print();
    return 0;
}