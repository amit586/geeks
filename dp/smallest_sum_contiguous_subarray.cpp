#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int smallestSum(vector<ll> &v,int n)
{
	int global_sum = INT_MAX;
	int local_sum =0;

	for(int i=0;i<n;i++)
	{	
		local_sum+=v[i];
		local_sum=min(local_sum,0);
		global_sum = min(global_sum,local_sum); 
	}
	return global_sum;
}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		std::vector<ll> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		cout<<smallestSum(v,n)<<endl;
		
	}
	return 0;
}
