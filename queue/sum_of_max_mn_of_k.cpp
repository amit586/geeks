#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		deque<int> mx;
		deque<int>mn;
		int ans=0;
		for(int i=0;i<k;i++)
		{
			while(!mx.empty() && arr[mx.back()]<=arr[i])
				mx.pop_back();
			mx.push_back(i);

			while(!mn.empty() && arr[mn.back()]>=arr[i])
				mn.pop_back();
			mn.push_back(i);
		}

		for(int i=k;i<n;i++)
		{
			//cout<<arr[mx.front()]<<" "<<arr[mn.front()]<<endl;
			ans+=(arr[mx.front()]+arr[mn.front()]);
			while(mx.front()<=i-k)
				mx.pop_front();
			while(mn.front()<=i-k)
				mn.pop_front();
			while(!mx.empty() && arr[mx.back()]<=arr[i])
				mx.pop_back();
			while(!mn.empty() && arr[mn.back()]>=arr[i])
				mn.pop_back();
			mn.push_back(i);
			mx.push_back(i);
		}
		//cout<<arr[mx.front()]<<" "<<arr[mn.front()]<<endl;
		ans+=(arr[mx.front()]+arr[mn.front()]);
		cout<<ans<<endl;


	}
	return 0;
}