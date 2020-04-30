#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(),v.end());
		int mx_len=0,local_len=1;
		for(int i=1;i<n;i++)
		{
			//cout<<v[i]<<" "<<v[i-1]<<" "<<local_len<<endl;
			if(v[i]==v[i-1]+1)
				local_len++;
			else if(v[i]==v[i-1])
				local_len=local_len;
			else
				local_len=1;
			mx_len=max(mx_len,local_len);
		}
		cout<<mx_len<<endl;
		

	}
	return 0;
}