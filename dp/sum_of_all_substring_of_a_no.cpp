#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		string s;
		cin>>s;
		int n = s.size();
		vector<int> dp(n);
		dp[0] = (s[0]-'0');
		for(int i=2;i<=n;i++)
			dp[i-1] = i*(s[i-1]-'0')+dp[i-2];
		int ll sum = 0;
		for(int i=n-1;i>=0;i--)
		{
			sum+=pow(10,n-1-i)*dp[i];
		}		
		cout<<sum<<endl;
	}
	return 0;
}
