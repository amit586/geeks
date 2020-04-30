#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		unordered_map<int,int> freq(n);
		vector<int> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];
		for(int i=0;i<n;i++)
		{
			if(k && freq.count(v[i])>0)
				k--;
			else
				freq[v[i]]++;			
		}
		cout<<freq.size()-k<<endl;
	}
	return 0;
}