#include <bits/stdc++.h>
using namespace std;

unordered_set <int> sieveofEratosthenis(int n)
{
	bool vis[n+1]={false};
	unordered_set<int> primes;
	vis[0]=1;
	vis[1]=1;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(vis[i]==0)
			for(int j=2;j*i<=n;j++)
				vis[i*j]=1;
	}
	for(int i=2;i<=n;i++)
		if(!vis[i])
			primes.insert(i);
	return primes;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		unordered_set<int> primes;
		unordered_map<int,int> freq;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i],freq[v[i]]++;
		primes = sieveofEratosthenis(n);
		
		for(auto it:freq)
			if(it.second>=k && primes.find(it.second)!=primes.end())
				cout<<it.first<<" ";
	}
	return 0;
}