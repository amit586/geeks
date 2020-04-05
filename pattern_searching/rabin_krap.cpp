#include <bits/stdc++.h>
long long P= 1000000007;
using namespace std;

class RabinKrap
{
	string text;
	int q = (int)10e9+7;
	long long power(int a,int n,long long P);
public:
	RabinKrap(const string t);
	void match(const string &pat);	
};

RabinKrap::RabinKrap(const string t)
{
	text = t;
}

long long RabinKrap::power(int a,int n,long long P)
{
	long long ans = 1;
	while(n>0)
	{
		if(n&1)
			ans = (ans*a)%P;
		n=n>>1;
		a = (a*a)%P;
	}
	return ans;
}

void RabinKrap::match(const string &pat)
{
	long long int p=0,t=0,h,j=0,M = pat.size();
	int d=26;
	h = power(26,M-1,P);
	for(int i=0;i<M;i++)
	{
		t = ((t*d)%P +text[i])%P;
		p = ((p*d)%P + pat[i])%P; 
	}

	for(int i=0;i<text.size()-M;i++)
	{
		// cout<<"T "<<t<<" p "<<p<<endl;
		if(t==p)
		{
			int j=0;
			for(;j<M;j++)
				if(text[i+j]!=pat[j])
					break;

			if(j==M)
				cout<<"pattern found at "<<i<<endl;
		}
		if(i+M<text.size())
		{
			t = (d*(t + P-(h*text[i])%P)%P + text[i+M])%P;
		}
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
		RabinKrap r(text);
		r.match(pat);
	}
	return 0;
}