#include<bits/stdc++.h>
#define MAX 11
using namespace std;

bool canPlace(int arr[][MAX],int n,int row,int col)
{
	for(int i=0;i<col;i++)
		if(arr[row][i]==1)
			return false;
	int x=row,y=col;
	while(x>=0 && x<n && y>=0 && y<n)
	{
		if(arr[x][y])
			return false;
		x--;
		y--;
	}
	x=row,y=col;

	while(x>=0 && x<n && y>=0 && y<n)
	{
		if(arr[x][y])
			return false;
		x++;
		y--;
	}
	return true;
}

void solution(int arr[][MAX],int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			if(arr[i][j]==1)
				cout<<j+1<<" ";
	}
	cout<<"] "
}
board printSolution(int arr[][MAX],int n,int col)
{
	if(col>=n)
	{
		solution(arr,n);
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(canPlace(arr,n,i,col))
		{
			arr[i][col]=1;
			printSolution(arr,n,col+1);
			arr[i][col]=0;
		}
	}
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int board[n][MAX];
		memset(board,0,sizeof(board));
		if(!printSolution(board,n,0))
			cout<<-1;
		cout<<endl;
	}
	return 0;
}