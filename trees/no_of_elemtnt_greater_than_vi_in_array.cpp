#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    multiset <int,greater<int>> m;
	    vector<int> ans(n);
	    for(int i=0;i<n;i++)
	    {
	       cin>>v[i];
	    }
	   	for(int i=n-1;i>=0;i--)
	   	{
	   		m.insert(v[i]);
	   		ans[i] = distance(m.upper_bound(v[i]),m.end());
	   	}
	   	for(int i=0;i<n;i++)
	   		cout<<ans[i]<<" ";
	   	cout<<endl;

	}
	return 0;
}