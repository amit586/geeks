#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int kadens(vector<int> &v,int n)
{
	vector<int> dp(n,1);
	int global_max=INT_MIN,global_max_len=1,local_max=0,local_max_len=1;
	for(int i=0;i<n;i++)
	{
		local_max+=v[i];
		
		global_max = max(global_max,local_max);
		local_max = max(local_max,0);
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
		string s;
		cin>>s;
		int n = s.size();	
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			if(s[i]=='0')
				v[i]=1;
			else
				v[i]=-1;
		}

		cout<<kadens(v,n)<<endl;

		
	}
	return 0;
}
