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

int count(int x,vector<int> &Y,int n,unordered_map<ll,ll> &um)
{
	if(x==0)
		return 0;
	if(x==1)
		return um[0];
	auto idx = upper_bound(all(Y),x);
	int ans = Y.end()-idx;
	ans+=(um[0]+um[1]);
	
	if(x==2)
		ans -=(um[3]+um[4]);
	if(x==3)
		ans+=(um[2]);
	return ans;
}

main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n,m;
		cin>>n>>m;
		std::vector<ll> v1(n),v2(m);
		unordered_map<ll,ll> um;
		for(int i=0;i<n;i++)	cin>>v1[i];
		for(int i=0;i<m;i++)	cin>>v2[i],um[v2[i]]++;

		sort(all(v1));
		sort(all(v2));
		int ans = 0;
		for(int i=0;i<n;i++)
			ans+=count(v1[i],v2,m,um);
		cout<<ans<<endl;		
	}
	return 0;
}
