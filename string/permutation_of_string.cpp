#include <bits/stdc++.h>
using namespace std;

void permute(string s,int l,int r,vector<string> &perm)
{
    if(l==r)
        perm.push_back(s);
    for(int i=l;i<=r;i++)
    {
        swap(s[i],s[l]);
        permute(s,l+1,r,perm);
        swap(s[i],s[l]);
    }
    
}

void prinPermutation(string s)
{

	    vector<string> perm;
	    permute(s,0,s.size()-1,perm);
	    sort(perm.begin(),perm.end());
	    for(int i=0;i<perm.size();i++)
	    	cout<<perm[i]<<" ";
	    cout<<endl;
}

int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    string s;
	    cin>>s;
	    sort(s.begin(),s.end());
	    //prinPermutation(s);
	    do {
	    	cout<<s<<" ";
	    }
	    while(next_permutation(s.begin(),s.end()));
	    cout<<endl;
	}
	return 0;
}