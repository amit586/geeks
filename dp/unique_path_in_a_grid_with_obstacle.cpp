#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int m,n;
		cin>>m>>n;
		vector<vector<int>> grid(m,vector<int>(n));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>grid[i][j];
		vector<vector<int>> path(m,vector<int>(n,0));

		for(int i=0;i<n && grid[0][i]!=1;i++)
			path[0][i]=1;

		for(int i=0;i<m && grid[i][0]!=1;i++)
			path[i][0]=1;

		for(int i=1;i<m;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(grid[i][j] !=1)
				{
					int x1=0,x2=0;
					if(grid[i-1][j]!=1)
						x1 = path[i-1][j];
					if(grid[i][j-1]!=1)
						x2 = path[i][j-1];
					path[i][j]=x1+x2;
				}
			}
		}

		cout<<path[m-1][n-1]<<endl;

	}
	return 0;
}