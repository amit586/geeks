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
		unordered_map<int,int> freq;
		int kth=-1,counter=0;
		vector<int>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i],freq[v[i]]++;
		for(int i=0;i<n;i++)
		{
			if(freq[v[i]]==1&& counter<k)
				counter++;
			if(counter==k)
			{	
				kth=v[i];
				break;
			}
		}
		cout<<kth<<endl;
	}
	return 0;
}