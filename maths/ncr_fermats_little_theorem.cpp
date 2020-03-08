#include <bits/stdc++.h>
#define ll long long
#define P 1000000007
using namespace std;

/// compute partial factorial n(n-1)(n-1)...(n-r+1) mod P 
ll fact(ll n,ll r)
{
	ll ans = 1;
	for(ll i=n;i>r;i--)
	{
		ans = (ans*i)%P;
	}
	return ans;
}

ll power(ll a,ll n)
{
	ll ans = 1;
	while(n)
	{
		if(n&1)
			ans = (ans*a)%P;
		n>>=1;
		a = (a*a)%P;
	}
	return ans;
}

ll ncr(ll n,ll r)
{
	if(r >n/2)
		r = n-r;

	ll num = fact(n,n-r);
	ll den = fact(r,1);
	cout<<"num "<<num<<" den "<<den<<endl;
	den = pow(den,P-2);
	return (num*den)%P;
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n,r;
		cin>>n>>r;
		cout<<ncr(n,r)<<endl;
	}
	return 0;
}