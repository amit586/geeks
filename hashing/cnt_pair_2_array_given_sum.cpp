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
		vector<int> v(m);
		unordered_map<int,int> hash;
		int temp;
		for(int i=0;i<n;i++)
			cin>>temp,hash[temp]++;
		int ans=0;
		for(int i=0;i<m;i++)
		{
			cin>>v[i];
		}
		int sum;
		cin>>sum;
		for(int i=0;i<m;i++)
		{
			if(hash.find(sum-v[i])!=hash.end())
				ans+=hash[sum-v[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}