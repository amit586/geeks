#include <bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int v[N][N];
int vis[N][N];

int minVertices(int mx)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		int mx = INT_MIN;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j],mx=max(mx,v[i][j]);
		cout<<minVertices(mx)<<endl;
	}
	return 0;
}