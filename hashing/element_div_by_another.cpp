#include<bits/stdc++.h>
using namespace std;

unordered_set<int> sieveOfEratosthenes(int mx)
{
	vector<bool> vis(mx+1,false);
	vis[0]=true;

	for(int i=2;i<=sqrt(mx);i++)
	{
		if(!vis[i])
			for(int j=i*2;j<=mx;j+=i)
				vis[j]=true;;
	}

	unordered_set<int> primes;
	for(int i=0;i<=mx;i++)
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
		int n;
		cin>>n;
		vector<int> v(n);
		int mx=INT_MIN;
		for(int i=0;i<n;i++)
			cin>>v[i],mx=max(mx,v[i]);

		unordered_set<int> primes = sieveOfEratosthenes(mx);
		unordered_set<int> present;

		for(int i=0;i<n;i++)
			if(primes.find(v[i])!=primes.end())
				present.insert(v[i]);
		
		for(int i=0;i<n;i++)
			for(auto it:present)
				if(v[i]!=it && v[i]%it==0)
					{cout<<v[i]<<" ";break;}

	}
	return 0;
}