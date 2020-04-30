#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n+1,0);
		unordered_map<int,int> hash;
		for(int i=1;i<=n;i++)
			cin>>v[i],v[i]+=((v[i-1]%k)+k)%k;
		int mx_len=0;
		hash[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]==0)
				mx_len=i;
			else if(hash.count(v[i]%k)!=0)
				mx_len = max(mx_len,i-hash[v[i]%k]),cout<<"i:"<<i<<" mx:"<<mx_len<<endl;
			else
				hash[v[i]%k]=i;
		}
		cout<<mx_len<<endl;

	}	
	return 0;
}