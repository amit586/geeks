#include <bits/stdc++.h>
using namespace std;

map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string roman;
		cin>>roman;
		int res=0;
		for(int i=roman.size()-1;i>=0;i--)
		{
			if(i>0 && m[roman[i]]>m[roman[i-1]])
				res+=(m[roman[i]]-m[roman[i-1]]),i--;
			else
				res+=m[roman[i]];
		}
		cout<<res<<endl;
	}
	return 0;
}