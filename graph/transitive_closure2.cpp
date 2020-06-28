#include <iostream>
using namespace std;
const int N=110;
int adj[N][N];
int dp[N][N];
int n;
int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	  cin>>n;
	  for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        cin>>adj[i][j];
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                adj[j][k] = adj[j][k]||(adj[j][i] and adj[i][k]);
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
      cout<<endl;
	}
	return 0;
}