#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,sum;
		cin>>n>>m>>sum;
		vector<vector<int>> v(n,vector<int>(m));
		unordered_map<int,pair<int,int>> hash;
		hash.reserve(n*n);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>v[i][j],hash[v[i][j]]={i,j};
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(hash.find(sum-v[i][j])!=hash.end() && hash[sum-v[i][j]].first >i)
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}