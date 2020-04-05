#include<bits/stdc++.h>
#define NO_OF_CHARS 256
using namespace std;

void match(const string &text,const string &pat)
{
	vector <int> bad_char(NO_OF_CHARS,-1);
	for(int i=0;i<pat.size();i++)
		bad_char[pat[i]]=i;

	int s = 0;
	int n = text.size();
	int m = pat.size();
	while(s<=n-m)
	{	
		int j=m-1;
		while(text[s+j]==pat[j])
			j--;
		if(j<0)
		{
			cout<<"pattern found at "<<s<<endl;
			s+=(s+m<n)?m-bad_char[text[m-1]]:1;
		}else
			s+=max(j-bad_char[text[s+j]],1);
	}
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string text,pat;
		cin>>text>>pat;
		match(text,pat);
	}
	return 0;
}