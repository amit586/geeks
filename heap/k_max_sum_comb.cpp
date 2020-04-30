#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n1,n2,k;
		cin>>n1>>n2>>k;
		vector<int> v1(n1),v2(n2);
		for(int i=0;i<n1;i++) cin>>v1[i];
		for(int i=0;i<n2;i++) cin>>v2[i];
		sort(all(v1),greater<int>()),sort(all(v2),greater<int>());
		priority_queue<int> pq;
		int ith=0,i=0,j=0;
		while(ith<k)
		{
			pq.push(v1[i]+v2[j]);
			if(v1[i+1]+v2[j]>v1[i]+v2[j+1])
				i=min(i+1,n1-1);
			else 
				j=min(j+1,n2-1);
			if(i==n1-1&& j==n1-1)
				break;
			ith++;
		}
		int ans;
		while(!pq.empty())
			cout<<pq.top()<<" ",pq.pop();
	}
	return 0;
}