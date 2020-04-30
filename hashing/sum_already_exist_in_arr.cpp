#include <bits/stdc++.h>
using namespace std;
struct myhash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
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
		vector<int>v(n);
		unordered_map<int,int,myhash> hash;
		for(int i=0;i<n;i++)
			cin>>v[i],hash[v[i]]++;
		vector<pair<int,int>> ans;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(hash.find(v[i]+v[j])!=hash.end())
					if((v[i]==0 || v[j]==0) && hash[v[i]+v[j]]>1)
						ans.push_back({v[i],v[j]});
					else if(v[i]!=0 || v[j]!=0)
						ans.push_back({v[i],v[j]});
		if(ans.size())
			for(int i=0;i<ans.size();i++)
				cout<<ans[i].first<<" "<<ans[i].second<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}