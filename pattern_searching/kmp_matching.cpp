#include<bits/stdc++.h>
using namespace std;

class KMP
{
	string s;
	void preprocess(string &pat,int lps[]);
public:
	KMP(string s_);
	void match(string pat);
};

KMP::KMP(string s_)
{
	s = s_;
}

void KMP::preprocess(string &pat,int lps[])
{
	int len = 0;
	int i=1;
	while(i<pat.size())
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len==0)
			{
				lps[i]=0;
				i++;
			}
			else
				len = lps[len-1];
		}
	}
}

void KMP::match(string pat)
{
	int lps[pat.size()]={0};
	preprocess(pat,lps);
	int j=0, M = pat.size(),i=0;
	while(i<s.size())
	{
		if(s[i]==pat[j])
		{
			i++;
			j++;
		}

		if(j==M)
		{
			cout<<"pattern found at "<<i-j<<endl;
			i++;
			j = lps[j-1];
		}
		else if(s[i]!=pat[j] && i<s.size())
		{
			if(j==0)
				i++;
			else
				j = lps[j-1];
		}
	}
}

int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    string s,pat;
	    cin>>s>>pat;
	    KMP k(s);
	    k.match(pat);
	}
	return 0;
}