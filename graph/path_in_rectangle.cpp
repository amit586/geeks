#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

void makeCircles(pair<int,int> centre,int raduis,vector<vector<int>> &maze)
{
	
		if(pow(x-i,2)+pow(y-j,2)<=pow(r,2))
			maze[i][j]=-1;

}

int main(int argc, char const *argv[])
{
	int m,n,k,r,x,y;
	cin>>m>>n>>k>>r;
	vector<pii> c(k);
	for(int i=0;i<k;i++)
		cin>>x>>y,c[i]=make_pair(x,y);
	vector<vector<int>>  maze(m,vector<int>(n,0));
	for(int i=0;i<k;i++)
	{
		makeCircles(c[i],r,maze);
	}


	return 0;
}