#include <bits/stdc++.h>
using namespace std;

struct myhash{
	size_t operator()(const string &s1)const{
		set<char> s;
		for(int i=0;i<s1.size();i++)
			s.insert(s1[i]);
		//sort(s.begin(),s.end());
		const int p=31;
		const int m=1e9+9;
		long long hash_value=0;
		long long pow=1;
		for(auto c:s)
		{
			hash_value+=(pow*(hash_value+(c-'a'+1)))%m;
			pow=(pow*p)%m;
		}
		//cout<<s1<<" hash value:"<<hash_value<<endl;
		return hash_value;
	}
};

struct mycomp{
	bool operator()(const string &s1,const string &s2)const {
		set<char> c1,c2;
		for(int i=0;i<s1.size();i++)
			c1.insert(s1[i]);

		for(int i=0;i<s2.size();i++)
			c2.insert(s2[i]);
			
		if(c1.size()!=c2.size())
			return false;
		auto it2=c2.begin();		
		for(auto it1:c1)
		{
			if(it1!=*it2)
				return false;
			it2++;
		}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector <string> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		unordered_map<string,vector<string>,myhash,mycomp> m;
		for(int i=0;i<n;i++)
			m[v[i]].push_back(v[i]);
		for(auto it:m)
		{
			for(int i=0;i<it.second.size();i++)
				cout<<it.second[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}