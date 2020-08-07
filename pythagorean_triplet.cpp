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

std::vector<ll> v(1010);

bool solve(){
		int n,temp;
		cin>>n;
		
		unordered_set<ll> s;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;
			s.insert(temp*temp);
		}
		n = s.size();
		int i = 0;
		for(auto it:s)
			v[i++]=it;
		sort(v.begin(),v.begin()+n);
		for(int a = n-1;a>=0;a--)
			for(int b = 0;b<a;b++)
				if(s.find(v[a]-v[b])!=s.end())
				{
					//cout<<v[a]<<" "<<v[b]<<" "<<a<<" "<<b<<endl;
					return true;
				}
		return false;
}


main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{

		cout<<(solve()?"Yes\n":"No\n");	
	}
	return 0;
}
