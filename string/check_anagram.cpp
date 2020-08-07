#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(const string &s1,const string &s2){
	int freq[26]={0};
	if(s1.size()!=s2.size())
		return false;
	
	int n = s1.size();
	for(int i=0;i<n;i++)
		freq[s1[i]-'a']++,freq[s2[i]-'a']--;

	for(int i=0;i<26;i++)
		if(freq[i])
			return false;
	
	return true;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s1,s2;
		cin>>s1>>s2;
		checkAnagram(s1,s2)?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}