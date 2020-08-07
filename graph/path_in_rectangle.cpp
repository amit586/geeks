#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

bool solve(vector<vector<int>> &maze,map<pii> &c,int r)
{
	
}


int main(int argc, char const *argv[])
{
	int m,n,k,r,x,y;
	cin>>m>>n>>k>>r;
	set<pii> c(k);
	for(int i=0;i<k;i++)
		cin>>x>>y,c.insert(make_pair(x,y));
	vector<vector<int>>  maze(m,vector<int>(n,0));
	
	cout<<solve(maze,c,r)<<endl;

	return 0;
}