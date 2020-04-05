#include <bits/stdc++.h>
#define MAX 6
using namespace std;

bool isAllowed(int arr[][MAX],int n,int x ,int y,int prevX,int prevY)
{
	if(x>=0 && x<n && y<n && y>=0 && !(x==prevX && y==prevY) && arr[x][y]==1)
		return true;
	return false;
}

bool solveMaze(int arr[][MAX],int n,int x,int y,int prevX,int prevY,vector<pair<int,int>> &path)
{
	if(x==n-1 && y==n-1)
		return true;

	int allMoves[4][2] = {{x+1,y},{x-1,y},{x,y+1},{x,y-1}};

	for(int i=0;i<4;i++)
	{
		if(isAllowed(arr,n,allMoves[i][0],allMoves[i][1],prevX,prevY))
		{
			if(solveMaze(arr,n,allMoves[i][0],allMoves[i][1],x,y,path))
			{	path.push_back(make_pair(allMoves[i][0],allMoves[i][1]));
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int arr[n][MAX];

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		vector<pair<int,int>> path;
		int x=0,y=0,prevX=-1,prevY=-1;
		solveMaze(arr,n,x,y,prevX,prevY,path);
		memset(arr,0,sizeof(arr));
		for(int i=0;i<path.size();i++)
		{
			arr[path[i].first][path[i].second]=1;
		}

		for(int i=0;i<n;i++)
		{	
			for(int j=0;j<n;j++)
			{	
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}