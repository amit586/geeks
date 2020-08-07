#include <bits/stdc++.h>
using namespace std;

void dfs(pair<int,int> &v,vector<vector<int>> &mat,int n,int m)
{
	mat[v.first][v.second]=-1;
	//cout<<v.first<<" "<<v.second<<endl;

	int x[] = {v.first+1, v.first+1, v.first-1, v.first-1, v.first,   v.first,   v.first-1, v.first+1};
	int y[] = {v.second+1,v.second-1,v.second+1,v.second-1,v.second+1,v.second-1,v.second,  v.second};
	
	for(int i=0;i<8;i++)
		if(x[i]>=0 and x[i]<n and y[i]>=0 and y[i]<m and mat[x[i]][y[i]]==1){
			pair<int,int> temp = make_pair(x[i],y[i]);
			dfs(temp,mat,n,m);
		}
				
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,u,v;
		cin>>n>>m;
		//map<pair<int,int>,int> vis;
		vector<vector<int>> mat(n,vector<int>(m));
		stack<pair<int,int>> s;
		for(int i=0;i<n;i++)
			for(int j = 0;j<m;j++)
			{
				cin>>mat[i][j];
				if(mat[i][j])
					s.push(make_pair(i,j));
			}
		int islands = 0;

		while(!s.empty())
		{
			pair<int,int> temp = s.top();
			s.pop();
			if(mat[temp.first][temp.second]==1)
			{
				islands++;
				dfs(temp,mat,n,m);
				//cout<<endl;
			}
		}
		cout<<islands<<endl;

	}
	return 0;
}