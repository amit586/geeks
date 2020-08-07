#include <bits/stdc++.h>
using namespace std;

string deleteDuplicate(string s)
{
	string res = "";
	int i=0;
	while(s[i])
	{
		if(s[i]!=s[i+1])
			res+=s[i++];
		if(s[i+1] && s[i]==s[i+1])
		{
			while(s[i+1] && s[i]==s[i+1])
				i++;
			i++;
		}

	}
	//cout<<res<<endl;
	//return res;
	if(res==s || res.size()<=1)
		return res;
	else 
		return deleteDuplicate(res);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string str;
		cin>>str;
		str = deleteDuplicate(str);
		cout<<str<<endl;
	}
	return 0;
}