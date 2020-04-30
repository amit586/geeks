#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<vector<int> > v(n,vector<int> (n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j];
		unordered_map<int,int> hash;

		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				///unordered_map<int,int> s;
				for(int j=0;j<n;j++)
					hash[v[i][j]]=i+1;
				// for(auto it:s)
				// 	if(it.second==1)
						
			}
			else
			{
				//unordered_map<int,int> s;
				for(int j=0;j<n;j++)
					if(hash.find(v[i][j])!=hash.end() && hash[v[i][j]]==i)
						hash[v[i][j]]=i+1;
				// for(auto it:s)
				// 	if(it.second==1 && hash[it.first]==i)
				// 		hash[it.first]=i+1;
			}
		}

		for(auto it:hash)
			if(it.second==n)
				cout<<it.first<<" ";
			//cout<<it.first<<" "<<it.second<<endl;
		//cout<<endl;
	}
	return 0;
}