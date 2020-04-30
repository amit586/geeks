#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_set<ll> generateFibo(ll mx)
{	
	unordered_set<ll> fibo;
	int i=0,j=1,k=i+j;
	fibo.insert(i);
	fibo.insert(j);
	while(k<=mx)
	{
		fibo.insert(k);
		i=j;
		j=k;
		k=i+j;
	}
	// for(auto it:fibo)
	// 	cout<<it<<" ";
	return fibo;
}

int main(int argc, char const *argv[])
{
	 int tc;
	 cin>>tc;
	 while(tc--)
	 {
	 	int n;
	 	cin>>n;
	 	vector<ll> v(n);
	 	ll mx=INT_MIN;
	 	for(int i=0;i<n;i++)
	 		cin>>v[i],mx=max(mx,v[i]);
	 	unordered_set<ll> fibo = generateFibo(mx);
	 	for(int i=0;i<n;i++)
	 		if(fibo.find(v[i])!=fibo.end())
	 			cout<<v[i]<<" ";
	 	cout<<endl;
	 	
	 }
	return 0;
}