#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		std::vector<ll> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}

		int exc=0,exc_new,inc=v[0];
		for(int i=1;i<n;i++)
		{
			exc_new = max(exc,inc);
			inc = v[i] + exc;
			exc = exc_new;
		}
		cout<<max(inc,exc)<<endl;

		
	}
	return 0;
}
