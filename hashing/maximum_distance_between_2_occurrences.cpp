// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<maxDistance(arr,n)<<endl;
    }
    return 0;
}// } Driver Code Ends
// your task is to complete this function
int maxDistance(int arr[], int n)
{
	unordered_map<int,pair<int,int>> m;
	int mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(m.find(arr[i])==m.end())
			m[arr[i]]={i,-1};
		else 
			m[arr[i]].second=i;
		mx = max(mx,m[arr[i]].second-m[arr[i]].first);

	}
	return mx;
}