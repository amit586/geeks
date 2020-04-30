#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		vector<int> v1(n),v2(m);
		unordered_map<int,int> hash;
		for(int i=0;i<n;i++)
			cin>>v1[i];
		for(int i=0;i<m;i++)
			cin>>v2[i],hash[v2[i]]++;
		int ith=0;
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			if(hash.count(v1[i])==0)
			{	ith++;
				if(ith==k)
					ans=v1[i];

			}
			if(ith==k)
				break;
		}
		cout<<ans<<endl;

	}
	return 0;
}