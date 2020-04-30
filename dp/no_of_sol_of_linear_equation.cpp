#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int NoOfSol(const vector<int> &v,int k,int n)
{
	vector<int> dp(n+1,0);
	dp[0]=1;
	for(int i=0;i<k;i++)
		for(int j=v[i];j<=n;j++)
			dp[j]+=dp[j-v[i]];
	return dp[n];
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
		std::vector<int> coff(k);
		for (int i = 0; i < k; ++i)
		{
			cin>>coff[i];
		}
		cout<<NoOfSol(coff,k,n)<<endl;
	}
	return 0;
}
