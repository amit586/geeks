#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> freq;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i],freq[v[i]]++;
		sort(v.begin(),v.end(),[](const int a,const int b)->bool{
			return (freq[a]>freq[b] || (freq[a]==freq[b] && a<b));
		});
		for(int i=0;i<n;i++)
			cout<<v[i]<<" ";
		cout<<endl;
		freq.clear();

	}
	return 0;
}