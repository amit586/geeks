#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		
		unordered_set<int> s;
		unordered_map<int,int> freq;
		
		for(int i=0;i<n;i++)
			s.insert(i+1);

		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(s.find(v[i])!=s.end())
				s.erase(v[i]);
			if(v[i]>=1 && v[i]<=n)
				freq[v[i]]++;
		}	
		auto it=s.begin();
		for(int i=0;i<n;i++)
		{
			if((v[i]>n || v[i]<1))
			{
				v[i]=*it;
				it++;
				

			}
			else if( (freq.find(v[i])!=freq.end() && freq[v[i]]>1))
			{
				freq[v[i]]--;
				v[i]=*it;
				it++;
			}
		}

		// for(int i=0;i<n;i++)
		// 	cout<<v[i]<<" ";
		// cout<<endl;
		//// ***** space optimized (not working )*** ///
		// vector<int> hash(n+1,0);
		// for(int i=0;i<n;i++)
		// {	cin>>v[i];
		// 	if(v[i]<=n && v[i]>0)
		// 		hash[v[i]]++;
		// }
		// int next=1;
		// for(int i=0;i<n;i++)
		// {
		// 	while(hash[next]==1)
		// 		next++;
		// 	if(hash[v[i]]!=1)
		// 		v[i]=next,next++,hash[v[i]]--;
		// }
		// for(int i=0;i<n;i++)
		// 	cout<<v[i]<<" ";
		// cout<<endl;
	}
	return 0;
}