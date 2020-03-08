#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int mn=arr[0],max_difference = -1;
		for (int i = 1; i < n; ++i)
		{
			max_difference  = max(max_difference,arr[i]-mn);
			mn = min(arr[i],mn);
		}
		cout<<max_difference<<endl;
	}
	return 0;
}