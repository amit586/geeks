#include<bits/stdc++.h>
using namespace std;


int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    string s;
	    cin>>s;
	    int i=0;
	    while(i<s.size())
	    {
	    	if((i+2)<s.size() && (s[i]=='R' && s[i+1]=='Y' && s[i+2]=='Y'))
	    		i+=3;
	    	else if((i+1)<s.size() && (s[i]=='R' && s[i+1]=='Y'))
	    		i+=2;
	    	else if(s[i]=='R')
	    		i++;
	    	else
	    		break;
	    }
	    i==s.size()?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}