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
		std::vector<ll> v(n),l(n,0),r(n,0);
		cin>>v[0];
		l[0]= v[0];
		for(int i=1;i<n;i++)	cin>>v[i],l[i] = max(l[i-1],v[i]);
		r[n-1]=v[n-1];
		for(int i=n-2;i>=0;i--)
			r[i] = max(r[i+1],v[i]);
		ll water = 0;
		for(int i=1;i<n-1;i++)
			water+=max((ll)0,min(l[i],r[i])-v[i]);
		cout<<water<<endl;
		
	}
	return 0;
}
