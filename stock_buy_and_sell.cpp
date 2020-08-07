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
		std::vector<ll> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		vector<int> stock;
		int i=0;
		bool bought = false;
		if(v[0]<v[1])
			stock.push_back(0),bought = true,i++;

		for(;i<n-1;i++)
		{
			if(v[i]<v[i-1] and v[i]<v[i+1] and !bought)
				stock.pb(i),bought=true;
			else if(v[i]>v[i+1] and v[i]>v[i-1] and bought)
				stock.pb(i),bought=false;
		}
		if(bought and v[n-1]>v[n-2])
			stock.push_back(n-1);
		// cout<<stock.size()<<endl;
		if(stock.size()==0)
		{
			cout<<"No Profit\n";
			continue;
		}
		for(int i = 0;i<stock.size();i+=2)
			cout<<"("<<stock[i]<<" "<<stock[i+1]<<") ";
		cout<<endl;

		
	}
	return 0;
}
