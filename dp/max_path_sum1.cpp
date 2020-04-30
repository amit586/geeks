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
		int n;
		cin>>n;
		vector<vector<int>> v(n,vector<int> (n));

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j];

		for(int i=1;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int x1=0,x2=v[i-1][j],x3=0;
				if((j-1)>=0)
					x1 = v[i-1][j-1];
				if((j+1)<n)
					x3 = v[i-1][j+1];
				v[i][j] = v[i][j]+max(x1,max(x2,x3));
			}
		}
		cout<<*max_element(v[n-1].begin(),v[n-1].end())<<endl;
	}
	return 0;
}