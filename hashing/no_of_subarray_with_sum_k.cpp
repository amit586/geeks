#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> pref(n+1,0);
		unordered_map<int,int> hash;
		int count=0;
		hash[0]=1;
		for(int i=1;i<=n;i++)
		{
			cin>>pref[i];
			pref[i]=pref[i]+pref[i-1];
			if(hash.find(pref[i]-k)!=hash.end())
				count+=hash[pref[i]-k];
			hash[pref[i]]++;
		}
		cout<<count<<endl;
	}
	return 0;
}