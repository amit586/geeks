#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define MAX 155555

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
		vector<vector<int>> v(n,vector<int>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j];

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i==0 && j == 0)
					continue;
				int x1 = ((j-1) && (i-1)>=0 ?v[i-1][j-1]:MAX);
				int x2 = ((j-1)>=0 ? v[i][j-1]:MAX);
				int x3 = ((i-1)>=0 ?v[i-1][j]:MAX);
				v[i][j] = v[i][j]+min(x3,min(x2,x1));
			}
		cout<<v[n-1][n-1]<<endl;
	}
	return 0;
}
