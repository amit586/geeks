#include <bits/stdc++.h>
#define py first
#define px second 
#define ll long long
#define INF (int)1e17
using namespace std;

bool comp(const pair<ll,ll> &p1,const pair<ll,ll> &p2)
{
	return p1.px<p2.px;
}

ll minDist(vector<pair<ll,ll>> &pts,ll n)
{
	sort(pts.begin(),pts.end(),comp);

	map<ll,ll> m;
	ll best = INF;
	m.insert(make_pair(pts[0].py,pts[0].px));
	int l= 0;
	for(int i=1;i<n;i++)
	{
		while(l<i && pts[i].px-pts[l].px>best)
			m.erase(pts[l++].py);

		auto lb = m.lower_bound(pts[i].py-best);
		auto ub = m.upper_bound(pts[i].py+best);

		for(auto it=lb;it!=m.end() && it!=ub;it++ )
			best = min(best,(ll)sqrt( pow(pts[i].px-it->second,2)+
				pow(pts[i].py-it->first,2) ) );
		m.insert(make_pair(pts[i].py,pts[i].px));
	}
	return best;

}


int main(int argc, char const *argv[])
{
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n;
		cin>>n;
		vector<pair<ll,ll>> pts(n);
		for(ll i=0;i<n;i++)
			cin>>pts[i].px>>pts[i].py;
		cout<<minDist(pts,n)<<endl;
	}
	return 0;
}