#include <bits/stdc++.h>
#define MAX 6
using namespace std;

tuple <int,int> returnMove(char move,int x,int y)
{
	if(move=='D')
		return make_tuple(x+1,y);
	else if(move=='R')
		return make_tuple(x,y+1);
	else if(move=='L')
		return make_tuple(x,y-1);
	else
		return make_tuple(x-1,y); 
}

bool Allowed(int arr[MAX][MAX],int vis[MAX][MAX],int n,int x,int y,int prevX,int prevY)
{
	if(x>=0 && x<n && y>=0 && y<n && !(x==prevX && y==prevY) && arr[x][y]==1 && vis[x][y]==0)
		return true;
	return false;
}

void findPath(int arr[MAX][MAX],int vis[MAX][MAX],int n,int x,int y,int prevX,int prevY,vector <string> &s,string &sol)
{
	if(x==n-1 && y==n-1)
	{
		s.push_back(sol);
		return;
	}
	char moves[4]={'D','L','R','U'};
	int x_,y_;
	for(int i=0;i<4;i++)
	{
		tuple<int,int> coordinate =returnMove(moves[i],x,y);
		x_ = get<0>(coordinate);
		y_ = get<1>(coordinate);
		if(Allowed(arr,vis,n,x_,y_,prevX,prevY))
		{
			sol+=moves[i];
			vis[x_][y_]=1;
			findPath(arr,vis,n,x_,y_,x,y,s,sol);
			vis[x_][y_]=0;
			sol.pop_back();
		}
	}

}


vector<string> printPath(int m[MAX][MAX], int n)
{   
	int vis[MAX][MAX];
	memset(vis,0,sizeof(vis));
	vector <string> s;
	string sol;
	findPath(m,vis,n,0,0,-1,-1,s,sol);
	return s;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[MAX][MAX];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];

		std::vector<string> result = printPath(arr,n);
		if(result.size()==0)
			cout<<-1;
		else
			for(int i=0;i<result.size();i++)
				cout<<result[i]<<" ";
		cout<<endl;
	}
}