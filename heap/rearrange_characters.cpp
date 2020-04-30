#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		int freq[26]={0};
		int mx=0,n=s.size();
		for(int i=0;i<s.size();i++)
			freq[s[i]-'a']++,mx=max(freq[s[i]-'a'],mx);
		if(n%2==0)
		{
			cout<<((mx>n/2)?0:1)<<endl;
		}
		else{
			cout<<((mx>(n+1)/2)?0:1)<<endl;
		}
	}
	return 0;
}