#include <bits/stdc++.h>
using namespace std;

int root(int parent[],int i){

	while(parent[i]!=i)
		parent[i]=parent[parent[i]],i = parent[i];
	return i;
}

void union_set(int parent[],int size[],int u,int v)
{
	int root_u = root(parent,u);
	int root_v = root(parent,v);
	
	if(root_v==root_u)
		return;

	if(size[root_u]>=size[root_v])
		parent[root_v]=parent[root_u],size[root_u]+=size[root_v];
	else
		parent[root_u]=parent[root_v],size[root_v]+=size[root_u];
}

bool find(int parent[],int u,int v)
{
	return root(parent,u)==root(parent,v);
}


void inititlize(int n)
{
	for(int i=0;i<n;i++)
		parent[i]=i,size[i]=1;
}

int parent[100000],size[100000];

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		inititlize(n);

	}
	return 0;
}