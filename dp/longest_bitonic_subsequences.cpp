#include <bits/stdc++.h>
using namespace std;


int LBS(std::vector<int> &arr,int n)
{
	int lis[n+1];
	lis[0]=1;

	for(int i=1;i<=n;i++)
	{
		int mx = INT_MIN;
		for(int j=1;j<i;j++)
		{
			if(arr[j-1]<arr[i-1])
				mx = max(mx,lis[j]);
		}
		if(mx==INT_MIN)
			lis[i]=1;
		else 
			lis[i]=1+mx;
	}

	int lds[n+1];
	lds[n]=1;

	for(int i=n;i>=1;i--)
	{
		int mx = INT_MIN;
		for(int j=n;j>i;j--)
		{
			if(arr[j-1]<arr[i-1])
				mx = max(mx,lds[j]);
		}
		if(mx==INT_MIN)
			lds[i]=1;
		else 
			lds[i]=1+mx;
	}

	int mx = INT_MIN;

	for(int i=1;i<=n;i++)
		mx = max(mx,lds[i]+lis[i]-1);
	return mx;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];

		cout<<LBS(v,n)<<endl;
	}
	return 0;
}