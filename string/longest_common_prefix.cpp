#include <bits/stdc++.h>
using namespace std;

int maxPref(vector<string> &s)
{
	int l = 0,n = s.size();
	for(int i=0;i < s[0].size();i++)
	{
		for(int j = 0;j<n-1;j++)
			if(s[j][i]!=s[j+1][i])
				return l;
		l++;
	}	
	return l;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<string > s(n);
		for(int i=0;i<n;i++)
			cin>>s[i];
		int l = maxPref(s);
		for(int i=0;i<l;i++)
			cout<<s[0][i];
		cout<<endl;
	}
	return 0;
}