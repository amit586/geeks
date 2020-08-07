#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int adj[N][N];
vector<int> color(N);

bool isBipertite(int n)
{
	for(int i=0;i<n;i++)
		color[i]=-1;
	queue<int> q;
    for(int i=0;i<n;i++)
        if(color[i]==-1)
        {
            q.push(i);
            color[i]=1;
        	while(!q.empty())
        	{
        		int u = q.front();
        		q.pop();
        		if(adj[u][u])
        		    return false;
        		for(int v=0;v<n;v++)
        		{
        			if(adj[u][v] and color[v]==-1)
        				color[v]=1-color[u],q.push(v);
        			else if(adj[u][v] and color[v]==color[u])
        				return false;
        		}
        	}
        }
	return true;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>adj[i][j];
		cout<<isBipertite(n)<<endl;
	}
	return 0;
}