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
	int TC=1;
	// cin>>TC;
	while(TC--)
	{
		string s;
		string pat;
		cin>>s>>pat;

		for(int i=0;i<s.size();i++)
		{
			int prev = i;
			int j=0;
			for(;j<pat.size();j++)
			{
				if(s[prev]==pat[j])
					prev++;
				else
					break;
			}
			//cout<<"i "<<i<<" j "<<j<<endl;
			if(j==pat.size())
			{
				cout<<"i "<<i<<endl;
				break;
			}
		}
		
	}
	return 0;
}
