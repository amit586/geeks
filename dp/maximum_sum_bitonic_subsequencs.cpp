#include <bits/stdc++.h>
using namespace std;

int maxSumBS(std::vector<int> v,int n)
{
	int lis[n+1]={0};
	lis[0]=1;

	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<i;j++)
			if(v[j-1]<v[i-1])
				mx = max(mx,lis[j]);
		lis[i]=v[i-1]+mx;
	}

	int lds[n+1]={0};

	for(int i=n;i>0;i--)
	{
		int mx=0;
		for(int j=n;j>i;j--)
			if(v[j-1]<v[i-1])
				mx = max(mx,lds[j]);
		lds[i] = v[i-1]+mx;
	}

	int mx=INT_MIN;

	for(int i=1;i<=n;i++)
		mx = max(mx,lis[i]+lds[i]-v[i-1]);
	return mx;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];

		cout<<maxSumBS(v,n);
	}
	return 0;
}