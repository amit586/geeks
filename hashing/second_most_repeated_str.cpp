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
		unordered_map<string,int> s;
		int mx1,mx2;
		mx1=mx2=0;
		string s1,s2;
		string temp;
		for(int i=0;i<n;i++)
			cin>>temp,s[temp]++;
		for(auto it:s)
		{	
			if(it.second>=mx1)
				mx2=mx1,mx1=it.second,s2=s1,s1=it.first;
			else if(it.second>=mx2)
				mx2=it.second,s2=it.first;
		}
		cout<<s2<<endl;
	}
	return 0;
}