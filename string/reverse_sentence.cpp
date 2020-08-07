#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	getline(cin,str);
	istringstream st(str);
	int tc;
	st>>tc;
	while(tc--)
	{
		getline(cin,str);
		vector<string> tokens;
		string token;
		istringstream inp(str);
		while(getline(inp,token,'.'))
			tokens.push_back(token);
		reverse(tokens.begin(), tokens.end());
		string ans = "";
		for(int i=0;i<tokens.size();i++)
		{
			ans+=tokens[i];
			if(i!=tokens.size()-1)
				ans+=".";
		}
		cout<<ans<<endl;
	}
	return 0;
}