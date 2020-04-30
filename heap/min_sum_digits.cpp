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
		for(int i=0;i<n;i++)	cin>>v[i];
		priority_queue<int,vector<int> ,greater<int>> minHeap(v.begin(),v.end());
		vector<int> int1,int2;
		bool toggle=true;

		while(!minHeap.empty())
		{
			if(toggle)
				int1.push_back(minHeap.top()),toggle=false;
			else
				int2.push_back(minHeap.top()),toggle=true;
			minHeap.pop();
		}
		reverse(int1.begin(),int1.end());
		reverse(int2.begin(),int2.end());
		
		int carry=0;
		vector<int> ans;

		for(int i=0;i<max(int1.size(),int2.size());i++)
		{
			int i1 = (i>(int)int1.size()-1)?0:int1[i];
			int i2 = (i>(int)int2.size()-1)?0:int2[i];
			ans.push_back((i1+i2+carry)%10);
			carry = (i1+i2+carry)/10;
		}

		if(carry!=0)
		{
			ans.push_back(carry);
		}

		reverse(ans.begin(),ans.end());
		int i=0;
		while(ans[i]==0)
			i++;
		for(;i<ans.size();i++)
			cout<<ans[i];
		cout<<endl;
	}
	return 0;
}