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
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int odd=0,even=0;
		if(n%2==0)	
		{
			int temp;
			f(i,0,n)
			{
				cin>>temp;
				if(temp%2==0)
					even++;
				else
					odd++;
			}
			if(odd>0 && even>0)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
		{
			int temp;
			f(i,0,n)
			{
				cin>>temp;
				if(temp%2==0)
					even++;
				else
					odd++;
			}
			if(odd>0)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}
