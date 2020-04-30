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
		vector<int>v1(n),v2(m);
		unordered_map<int,int> hash;
		int sum=0;
		for(int i=0;i<n;i++)
			cin>>v1[i],hash[v1[i]]++,sum+=v1[i];

		for(int i=0;i<m;i++)
		{
			cin>>v2[i];
			if(hash.find(v2[i])==hash.end())
				sum+=v2[i];
			else
				sum-=v2[i];
		}
		cout<<sum<<endl;


	}
	return 0;
}