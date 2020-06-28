#include <bits/stdc++.h>
using namespace std;

int dfs(int i,vector<int> &parent,vector<bool> &vis,vector<int> &depth,int &mxdepth)
{
	if(vis[i]==true)
		return depth[i];
	if(parent[i]==-1)
	{
		depth[i]=0;
		return depth[i];
	}

	depth[i]=dfs(parent[i],parent,vis,depth,mxdepth)+1;
	mxdepth = max(mxdepth,depth[i]);
	vis[i]=true;

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> parent(n);
	for(int i=0;i<n;i++)
		cin>>parent[i];
	vector<bool> vis(n,0);
	vector<int> depth(n,0);
	int mxdepth=0;
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i,parent,vis,depth,mxdepth);	
	cout<<mxdepth<<endl;
	return 0;
}