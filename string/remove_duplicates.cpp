#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	getline(cin,s);
	istringstream inp(s);
	int tc;
	inp>>tc;
	while(tc--)
	{
		
		getline(cin,s);
		int arr[300]={0};
		for(int i=0;i<s.size();i++)
			arr[s[i]]++;
		for(int i=0;i<s.size();i++)
			if(arr[s[i]])
				cout<<s[i],arr[s[i]]=0;
		cout<<endl;
	}
	return 0;
}