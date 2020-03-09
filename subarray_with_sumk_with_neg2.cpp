#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n;
		int arr[n+1];
		arr[0]=0;
		for(int i=1;i<n+1;i++)
		{
			cin>>arr[i];
			arr[i]+=arr[i-1];
		}
		cin>>k;
		int count=0;
		unordered_map <int,int> m;
		m[0]=1;
		
		for(int i=1;i<n+1;i++)
		{
			if(m.find(arr[i]-k)!=m.end())
				count+=m[arr[i]-k];
			if(m.find(arr[i])==m.end())
				m[arr[i]]=0;
			m[arr[i]]++;
		}
		cout<<count<<endl;
	}
	
}
