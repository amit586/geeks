#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		int m1,m2,m3,v1,v2,v3;
		m1=m2=m3=INT_MIN;
		unordered_map<int,int> hash;

		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			hash[v[i]]++;
			
		//	cout<<v1<<" "<<v2<<" "<<v3<<endl;
		}
		for(auto it:hash)
		{
			if(it.second>=m1)
				m3=m2,m2=m1,m1=it.second,
				v3=v2,v2=v1,v1=it.first;
			else if(it.second>=m2)
				m3=m2,m2=it.second,v3=v2,v2=it.first;
			else if(it.second>=m3)
				m3=it.second,v3=it.first;
		}
		cout<<v1<<" "<<v2<<" "<<v3<<endl;
	}
	return 0;
}