#include <bits/stdc++.h>
#define MAX 510
#define INF 100000000
#define f first
#define s second
using namespace std;
int getMin(int sol[][MAX],int i,int j,int n,int m)
{
	int nbx[4]={i,i,i-1,i+1};
	int nby[4]={j+1,j-1,j,j};
	int mn = INF;
	for(int i=0;i<4;i++)
	{
		if(nbx[i]>=0 && nbx[i]<n && nby[i]>=0 && nby[i]<m)
			mn = min(mn,sol[nbx[i]][nby[i]]);
	}
	return mn;
}

void findDist(int arr[][MAX],int sol[][MAX],int n,int m,pair<int,int> pt,queue<pair<int,int>> &q)
{
	int nbx[4]={pt.f,pt.f,pt.f-1,pt.f+1};
	int nby[4]={pt.s+1,pt.s-1,pt.s,pt.s};

	for(int i=0;i<8;i++)
	{
		if( nbx[i]>=0 && nbx[i]<n && nby[i]>=0 && nby[i]<m && sol[nbx[i]][nby[i]]==INF )
		{
			int mn = 1+getMin(sol,nbx[i],nby[i],n,m);
			if(mn!=INF)
			{
				sol[nbx[i]][nby[i]]=mn;
				q.push(make_pair(nbx[i],nby[i]));
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		int arr[n][MAX];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		int sol[n][MAX];
		queue<pair<int,int> > q;

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(arr[i][j]==1)
					sol[i][j]=0,q.push(make_pair(i,j));
				else 
					sol[i][j]=INF;
		
		while(1)
		{
			int computed = q.size();
			if(computed==0)
				break;
			while(computed>0)
			{
				findDist(arr,sol,n,m,q.front(),q);
				q.pop();
				computed--;
			}
			//cout<<q.size()<<endl;
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<sol[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}