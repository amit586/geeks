#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll a,ll n,ll p)
{
	// returns a^n % p;
	ll ans=1;
	while(n>0)
	{
		if(n&1)  
			ans=(ans*a)%p;
		n>>=1;
		a = (a*a)%p;
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll a,n,m;
		m = 10e9 + 7;
		cin>>a>>n;
		cout<<power(a,n,m)<<endl;
	}
	return 0;
}