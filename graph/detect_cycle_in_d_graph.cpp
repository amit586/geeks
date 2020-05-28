// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool check(int i,vector<int> adj[],vector<bool> &vis,vector<bool> &rec)
{
	// if(vis[i]==false)
	// {
		rec[i]=true;
		vis[i]=true;
		for(auto it:adj[i])
		{
			if(!vis[it] && check(it,adj,vis,rec))
				return true;
			else if(rec[it])
				return true;
		}
//	}
	rec[i]=false;
	return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> vis(V,false),rec(V,false);
    for(int i=0;i<V;i++)
    	if(check(i,adj,vis,rec))
    		return true;
    return false;

}

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        
        int v, e;
        cin >> v >> e;
        
        vector<int> adj[v];
        
        for(int i =0;i<e;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        cout << isCyclic(v, adj) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends