#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		string s;
		cin>>s;
		n = s.size();

		int hash[26];
		memset(hash,-1,sizeof(hash));
		int j = 0,mxLen = 1;
		hash[s[0]-'a']=0;
		for(int i=1;i<n;i++)
		{
			if(hash[s[i]-'a']==-1)
				mxLen = max(mxLen,i-j+1);
			else
				while(j<=hash[s[i]-'a'])
					hash[s[j]-'a']=-1,j++;
				
			hash[s[i]-'a']=i;
			//cout<<i<<": "<<mxLen<<endl;
		}
		cout<<mxLen<<endl;
	}
	return 0;
}