#include <bits/stdc++.h>
#define MAX 105
#define f first
#define s second
using namespace std;

void rott(int arr[][MAX],int n,int m,pair<int,int> t,queue<pair<int,int>> &q,int &dest)
{
	int pos[4][2] = {{t.f+1,t.s},{t.f-1,t.s},{t.f,t.s-1},{t.f,t.s+1}};
	for(int i=0;i<4;i++)
	{
		if(pos[i][0]<n && pos[i][0]>=0 && pos[i][1]<m && pos[i][1]>=0 && arr[pos[i][0]][pos[i][1]]==1)
		{
			arr[pos[i][0]][pos[i][1]]=2;
			dest++;
			q.push(make_pair(pos[i][0],pos[i][1]));
		}
	}
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,cnt=0;
		cin>>n>>m;
		queue<pair<int,int>>q;
		int arr[n][MAX];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>arr[i][j];
				if(arr[i][j]==2)
					q.push(make_pair(i,j));
				else if(arr[i][j]==1)
					cnt++;
			}

		if(cnt==0)
		{
			cout<<0<<endl;
			continue;
		}
		int dist=0;
		int time=0;

		while(1)
		{
			int rottenCount = q.size();
			if(rottenCount==0)
				break;
			while(rottenCount>0)
			{

				rott(arr,n,m,q.front(),q,dist);
				q.pop();
				rottenCount--;
			}
			time++;
		}
		if(dist==cnt)
			cout<<time-1<<endl;
		else 
			cout<<-1<<endl;

	}
	return 0;
}