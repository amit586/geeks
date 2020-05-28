// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices

*/

bool check(int i,vector<int> adj[],int parent,vector<bool> &vis)
{
    vis[i]=true;
    for(auto it:adj[i])
        if(!vis[it])
        {   if(check(it,adj,i,vis))
              return true;
        }
        else if(vis[it] && parent!=it)
            return true;
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   vector<bool> vis(V,false);
   for(int i=0;i<V;i++)
        if(!vis[i])
            if(check(i,adj,-1,vis))
                return true;
    return false;
   
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends