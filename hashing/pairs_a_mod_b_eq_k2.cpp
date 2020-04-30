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
		vector<int> v(n);
		int pairs=0;
		for(int i=0;i<n;i++)
			cin>>v[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j && v[i]%v[j]==k)
					pairs++;
		cout<<pairs<<endl;
	}
	return 0;
}