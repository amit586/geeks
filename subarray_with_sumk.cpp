#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long n,s;
	    cin>>n>>s;
	    long long arr[n+1];
	    arr[0]=0;
	    for(int i=1;i<n+1;i++)
	        cin>>arr[i];
	    for(int i=1;i<n+1;i++)
	        arr[i]+=arr[i-1];
	   int i=1,j=0;
	    for(;i<n+1;i++)
	    {
	    	while(arr[i]-arr[j]>s)
				j++;
			if(arr[i]-arr[j]==s)
				break;	
		}
		if(arr[i]-arr[j]==s)
			cout<<j+1<<" "<<i<<endl;
		else
			cout<<-1<<endl;
	    
	}
	return 0;
}
