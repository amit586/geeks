#include <bits/stdc++.h>
using namespace std;

int populateCount(const char &emp,unordered_map<char,vector<char>> &manager,
	vector<bool> &vis,unordered_map<char,int> &empCount)
{
	if(manager.find(emp)==manager.end())
	{
		empCount[emp]=1;
		return 1;
	}
	else if(empCount.find(emp)!=empCount.end())
		return empCount[emp];
	else
	{
		int count=1;
		for(int i=0;i<manager[emp].size();i++)
		{
			if(manager[emp][i]!=emp)
				count+=populateCount(manager[emp][i],manager,vis,empCount);
		}
		empCount[emp]=count;
		return count;
	}

}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<pair<char,char>> v(n);
		unordered_map<char,vector<char>> manager;
		for(int i=0;i<n;i++)
			cin>>v[i].first>>v[i].second,manager[v[i].second].push_back(v[i].first);
		for(auto it:manager)
		{
			cout<<"key:"<<it.first<<" ";
			for(auto i:it.second)
				cout<<i<<" ";
			cout<<endl;
		}

		unordered_map<char,int> empCount;
		vector<bool> vis(n,false);
		for(int i=0;i<n;i++)
			populateCount(v[i].second,manager,vis,empCount);

		for(auto it:empCount)
			cout<<it.first<<" "<<it.second<<endl;
		
	}
	return 0;
}