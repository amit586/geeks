#include<bits/stdc++.h>
using namespace std;

int maxSum(vector <int> &v,int n,int k)
{
	int sum = 0;
	for(int i=n-1;i>0;--i)
	{
		if(v[i]-v[i-1]<k)
		{
			sum+=v[i];
			sum+=v[i-1];
			--i;
		}
	}
	return sum;		
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		
		sort(v.begin(),v.end());

		cout<<maxSum(v,n,k)<<endl;
	}
	return 0;
}