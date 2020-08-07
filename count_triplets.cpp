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
		unordered_set<ll> s;
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			s.insert(v[i]);
		}
		int count = 0;

		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				if(s.find(v[i]+v[j])!=s.end())
					count++;
		count>0?cout<<count<<endl:cout<<-1<<endl;
		
	}
	return 0;
}
