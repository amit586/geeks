#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum;
		cin>>n>>sum;
		vector<int> v1(n),v2(n),v3(n),v4(n);
		
		for(int i=0;i<n;i++)
			cin>>v1[i];

		for(int i=0;i<n;i++)
			cin>>v2[i];

		for(int i=0;i<n;i++)
			cin>>v3[i];

		for(int i=0;i<n;i++)
			cin>>v4[i];

		unordered_map<int,int>m1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(v1[i]+v2[j]<=sum)
					m1[v1[i]+v2[j]]++;
		int pairs=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(v3[i]+v4[j]<=sum && m1.find(sum-v3[i]-v4[j])!=m1.end())
					pairs+=m1[sum-v3[i]-v4[j]];
		cout<<pairs<<endl;
	}
	return 0;
}