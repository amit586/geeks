#include <bits/stdc++.h>
#define MAX 500
using namespace std;

void createPattern(int arr[][MAX],int start,int end)
{
	if(start==end)
	{
		arr[start][end]=start+1;
		return;
	}
	else
	{
		for(int i=start;i<=end;i++)
		{	
			arr[start][i]=start+1;
			arr[end][i]=start+1;
			arr[i][start]=start+1;
			arr[i][end]=start+1;
		}
		createPattern(arr,start+1,end-1);
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
		n--;
		int arr[2*n+1][MAX];
		createPattern(arr,0,2*n);
		for(int i=0;i<2*n+1;i++)
		{
			for(int j=0;j<2*n+1;j++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}