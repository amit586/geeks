#include<bits/stdc++.h>
#define ll long long
#define P 1000000007
using namespace std;

int prime[]={3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
	53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,107};
long long primeInv[26];

long long modInv(int pr,ll md)
{
	long long pow = md-2;
	ll ans=1;
	while(pow)
	{
		if(pow&1)
			ans = (ans*pr)%md;
		pow>>=1;
		pr=(pr*pr)%md;
	}
	return ans;
}



int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;

	for(int i=0;i<26;i++)
		primeInv[i]=modInv(prime[i],P);

	while(tc--)
	{
		string s1,s2;
		cin>>s1>>s2;
		long long hash2=1,hash1 = 1;
		for(int i=0;i<s2.size();i++)
		{
			hash2= (hash2*prime[s2[i]-'a']+P)%P;
			hash1= (hash1*prime[s1[i]-'a']+P)%P;

			
		}

		ll hasht = hash2;
		hasht = (hasht*primeInv['f'-'a'])%P;
		if(hasht<0)
			hasht+=P;
		hasht = (hasht*prime['f'-'a'])%P;
		if(hasht<0)
			hasht+=P;
		cout<<hasht<<endl;
		int anagrams=0;
		for(int i=0;i<s1.size()-s2.size();i++)
		{
			if(hash2==hash1)
				anagrams++;
			cout<<"h1:"<<hash1<<" h2:"<<hash2<<endl;
			hash1=(hash1*prime[s1[i+s2.size()]-'a'])%P;
			if(hash1<0)
				hash1+=P;
			hash1=(hash1*primeInv[s1[i]-'a'])%P;
			if(hash1<0)
				hash1+=P;
		}
		if(hash1==hash2)
			anagrams++;
		cout<<anagrams<<endl;


	}
	return 0;
}