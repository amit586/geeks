#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    int n,s;
	    cin>>n>>s;
	    vector<int> v(n);
	    for(int i=0;i<n;i++)    cin>>v[i];
	    int l=0,r=0,sum =0;
	    
	    while(r<n)
	    {
	        
	        while(sum<s and r<n)
	        	sum+=v[r++];
	        while(sum>s and l<n)
	        	sum-=v[l++];
	        if(sum==s)
	        	break;
	        //cout<<sum<<" "<<l<<" "<<r<<endl;

	    }
	    sum==s?cout<<l+1<<" "<<r<<endl:cout<<-1<<endl;
	    
	}
	return 0;
}