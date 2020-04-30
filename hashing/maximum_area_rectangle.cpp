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
		vector<int> v(n);
		unordered_map<int,int,myhash> um;
		for(int i=0;i<n;i++)
			cin>>v[i],um[v[i]]++;
		
		int mx1=0,mx2=0;
		for(auto it:um)
		{
			if(it.second>1)
			{
				if(it.first>mx1)
					mx2=mx1,mx1=it.first;
				else if(it.first!=mx1 && it.first>mx2)
					mx2 = it.first;
			}
		}
		cout<<mx1<<"*"<<mx2<<endl;

	}
	return 0;
}