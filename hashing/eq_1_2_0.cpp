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
		int n=s.size();
		vector<int> z(n,0),o(n,0),t(n,0);
		if(s[0]=='0')
			z[0]=1;
		else if(s[0]=='1')
			o[0]=1;
		else 
			t[0]=1;
		for(int i=1;i<n;i++)
		{
			if(s[i]=='0')
				z[i]=1;
			else if(s[i]=='1')
				o[i]=1;
			else 
				t[i]=1;
			z[i]=z[i]+z[i-1];
			o[i]=o[i]+o[i-1];
			t[i]=t[i]+t[i-1];
		}

		for(int i=0;i<n;i++)
			cout<<z[i]<<" "<<o[i]<<" "<<t[i]<<endl;
		int count=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
				if(z[i]-z[j] == o[i]-o[j] && o[i]-o[j]== t[i]-t[j] )
					count++;
		}
		cout<<count<<endl;
	}
	return 0;
}