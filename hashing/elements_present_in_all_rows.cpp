#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<int>> v(n,vector<int>(m));
		//vector<unordered_set<int>> hash(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>v[i][j];//,hash[i].insert(v[i][j]);
		// vector<int> ans;

		// for(auto it:hash[0])
		// {
		// 	bool flag=true;
		// 	for(int i=1;i<n;i++)
		// 	{
		// 		if(hash[i].find(it)==hash[i].end())
		// 		{
		// 			flag=false;
		// 			break;
		// 		}
		// 	}
		// 	if(flag	)
		// 		ans.push_back(it);
		// }

		/// *** space optimized solution *** ///////
		unordered_map<int,int> hash;
		for(int i=0;i<n;i++)
		{
			if(i==0)
				for(int j=0;j<m;j++)
					hash[v[0][j]]=i+1;
			else
				for(int j=0;j<m;j++)
				 	if(hash.find(v[i][j])!=hash.end()&& hash[v[i][j]]==i)
						hash[v[i][j]]=i+1;
		}
		for(auto it:hash)
			if(it.second==n)
				cout<<it.first<<" ";
			// // else 
			// 	cout<<it.first<<" "<<it.second<<endl;
		cout<<endl;
	}
	return 0;
}