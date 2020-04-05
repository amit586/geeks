#include<bits/stdc++.h>
#define N 7
using namespace std;

bool allowed(int arr[N][N],int x,int y)
{
	if(x>=0 && x<N && y>=0 && y<N && arr[x][y]==-1)
			return true;
	return false;
}

bool solveTour(int arr[N][N],int i,int j,int count)
{
	if(count==N*N)
		return true;
	int moves[8][2]={{i+2,j+1},{i+2,j-1},
				 	 {i-2,j+1},{i-2,j-1},
				     {i+1,j+2},{i+1,j-2},
				     {i-1,j+2},{i-1,j-2}};

	for(int m=0;m<8;m++)
	{
		if(allowed(arr,moves[m][0],moves[m][1]))
		{
			//cout<<moves[m][0]<<" "<<moves[m][1]<<endl;
			arr[moves[m][0]][moves[m][1]]=count;
			if(solveTour(arr,moves[m][0],moves[m][1],count+1))
				return true;
			arr[moves[m][0]][moves[m][1]]=-1;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int board[N][N];
	int i=1;
	memset(board,-1,sizeof(board));
	board[0][0]=0;
	if(solveTour(board,0,0,i))
	{
		for(int i=0;i<N;i++)
		{
			for (int j = 0; j < N; ++j)
				cout<<board[i][j]<<"\t";
			cout<<endl<<endl;
		}
	}else
		cout<<"NO solution found"<<endl;
	return 0;
}