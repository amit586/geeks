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

int arr[10000010];

main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n,m;
		cin>>n;
		ll sum = 0;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>m;
		sort(arr,arr+n);
		int mn_diff = INT_MAX;
		// cout<<"arr<< ";
		// for(int i=0;i<n;i++)
		// 	cout<<arr[i]<<" ";
		// cout<<endl;
		
		for(int i = 0;i+m<=n;i++)
			mn_diff = min(mn_diff,arr[i+m-1]-arr[i]);
		cout<<mn_diff<<endl;
		
	}
	return 0;
}
