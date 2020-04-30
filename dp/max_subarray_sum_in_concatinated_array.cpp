#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int kadens(vector<int> &v,int n,int k)
{
	int len = n*k;
	int local_max=0,global_max=INT_MIN;
	for(int i=0;i<len;i++)
	{
		local_max+=v[i%n];
		local_max = max(0,local_max);
		global_max = max(local_max,global_max);
	}	
	return global_max;
}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n,k;
		cin>>n>>k;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		cout<<kadens(v,n,k)<<endl;
		
	}
	return 0;
}
