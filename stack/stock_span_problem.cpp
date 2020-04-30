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
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];

		stack <int> s;
		s.push(0);
		vector<int> span(n,1);
		for(int i=1;i<n;i++)
		{
			while(!s.empty() && v[s.top()]<=v[i] )
					s.pop();
			span[i] = s.empty()?i+1:i-s.top();
			s.push(i);
		}

		for(int i=0;i<n;i++)
			cout<<span[i]<<" ";
		cout<<endl;
	}
	return 0;
}
