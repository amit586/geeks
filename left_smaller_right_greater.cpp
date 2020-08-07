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
		std::vector<ll> v(n),mx(n),mn(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		mx[0]=v[0];
		for(int i=1;i<n;i++)
			mx[i] = max(mx[i-1],v[i]);
		mn[n-1] = v[n-1];
		for(int i=n-2;i>=0;i--)
			mn[i] = min(mn[i+1],v[i]);
		bool flag=false;
		int i;
		for(i=1;i<n-1;i++)
			if(v[i]<=mn[i+1] and v[i]>=mx[i-1])
			{
				flag=true;
				break;
			}

		flag?cout<<v[i]<<endl:cout<<-1<<endl;

		
	}
	return 0;
}
