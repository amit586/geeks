#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define MAX 10e6+239
using namespace std;

int lsp[(int)MAX],len;

string solve_palindrome(const string &s)
{
	string a = s;
	reverse(a.begin(),a.end());
	a = s + "#" + a;
	len=0;
	int i=1;
	while(i<a.size())
	{
		if(a[i]==a[len])
		{
			len++;
			lsp[i]=len;
			i++;
		}
		else
		{
			if(len==0)
			{
				lsp[i]=0;
				i++;
			}
			else
				len=lsp[len-1];
		}
	}
	return a.substr(0,len);

}


int main()
{
	fio
	int TC;
	cin>>TC;
	while(TC--)
	{
		string t;
		cin>>t;

		int l=0;
		while(l<t.size()-1-l)
			if(t[l]!=t[t.size()-1-l])
				break;
			l++;

		if(l>0)
			cout<<t.substr(0,l);
		if(l>0)
			cout<<t.substr(t.size()-l,l);
		cout<<endl;
	}
	return 0;
}
