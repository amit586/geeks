#include<bits/stdc++.h>
using namespace std;
int main()
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
		bool sharp=true;
		int prefixEnd = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]<i)
			{
				prefixEnd=i;
				break;
			}
		}
		if(arr[prefixEnd]==arr[prefixEnd+1])
		{
			cout<<"NO\n";
			continue;
		}
		for(int i=prefixEnd+1;i<n;i++)
		{
			if(arr[i]<n-i-1)
				sharp=!sharp;
		}
		sharp?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}
