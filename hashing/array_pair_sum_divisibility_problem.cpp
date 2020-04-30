#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n;
		vector<int> v(n);
		long long sum=0;
		unordered_map<int,int> m;
		for(int i=0;i<n;i++)
			cin>>v[i];
		cin>>k;
		unordered_map<int,int> index;
		for(int i=0;i<n;i++)
		    sum+=v[i],m[v[i]%k]++,index[v[i]]=i;
		
		if(n%2==1 || sum%k!=0 )
		{
			cout<<"False"<<endl;
			continue;
		}
		vector<bool> vis(n,false);
		bool ans=true;
		for(int i=0;i<n;i++)
		{
				if(v[i]%k!=0 && m.count(k-v[i]%k)>0 && m.count(v[i]%k)>0)
				{
					m[k-v[i]%k]--;
					m[v[i]%k]--;
				}
				else if(v[i]%k==0&& m.count(v[i]%k)>=2)
					m[v[i]]-=2;
				else
				{
					ans=false;
					break;
				}
		}
		ans?cout<<"True"<<endl:cout<<"False"<<endl;

	}
	return 0;
}