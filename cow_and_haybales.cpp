#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,days;
		cin>>n>>days;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int x=0;
		for(int i=1;days>0 && i<n;i++)
		{
			x = min(arr[i],days/i);
			arr[0]+=x;
			days-=x*i;
		}
		cout<<arr[0]<<endl;
	}
	return 0;
}
