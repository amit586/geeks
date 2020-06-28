#include <bits/stdc++.h>
using namespace std;

int p1,p2,a,b;
int prime[10000];
vector<int> pr;

bool compare(int x,int y)
{
	string s1=to_string(x),s2=to_string(y);
	int c=0;
	if(s1[0]!=s2[0])
		c++;
	if(s1[1]!=s2[1])
		c++;
	if(s1[2]!=s2[2])
		c++;
	if(s1[3]!=s2[3])
		c++;
	return c==1;
}

void sieveOfEratosthenes()
{
	int j;
	memset(prime,0,p2+1);
	for(int i=2;i<=p2;i++)
	{
		if(prime[i]!=1)
		{
			if(i>1032)
				pr.push_back(i);
			j=2;
			while(i*j<=p2)
				prime[i*j]=1,j++;
		}
	}
}

int bfs(int u,int v,vector<int> *adj,int n)
{
	vector<int> vis(n,0);
	queue<int> q;
	q.push(u);
	vis[u]=1;
	while(!q.empty())
	{
		int temp =q.front();
		q.pop();
		for(auto it:adj[temp])
		{
			if(!vis[it])
				q.push(it),vis[it]=vis[temp]+1;
			if(it==v)
				return vis[it]-1;
		}
	}
}

int main(int argc, char const *argv[])
{
	p1=1373,p2=8017;
	sieveOfEratosthenes();
	cout<<pr.size()<<endl;
	vector<int> adj[pr.size()+1];
	for(int i=0;i<pr.size();i++)
		for(int j=i+1;j<pr.size();j++)
			if(compare(pr[i],pr[j]))
				adj[i].push_back(j),adj[j].push_back(i);
	for(int i=0;i<pr.size();i++)
	{
		if(pr[i]==p1)
			a=i;
		else if(pr[i]==p2)
			b=i;
	}
	cout<<bfs(a,b,adj,pr.size()+1)<<endl;
	return 0;
}