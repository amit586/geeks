#include<stdio.h>
#include<iostream>
#include<climits>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
#include<chrono>
#include<unordered_map>
#include<unordered_set>

#define mod     1000000007
#define pi      3.1415926535897932384626433832795
#define fio     ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define ll      long long
#define ld      long double
#define pb      push_back
#define all(x)  x.begin(),x.end()
#define f       first
#define s       second
#define int     ll

using namespace std;
std::vector<ll> v(1000040);

main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		ll sr = 0,sl = 0;
		for (int i = 0; i < n; ++i)
			cin>>v[i],sr+=v[i];

		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		sr-=v[0];
		// sl+=v[0];
		int i=1;
		for(;i<n;i++)
		{
			sl+=v[i-1];
			sr-=v[i];
			if(sl==sr)
				break;
		}
		i!=n?cout<<i+1<<endl:cout<<-1<<endl;
		
	}
	return 0;
}
