#include <bits/stdc++.h>
using namespace std;

int sumofDiv(int n)
{
	int sum=1;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			if(n/i==i)
				sum+=i;
			else
				sum+=(n/i + i);
	}
	//cout<<"sod "<<n<<":"<<sum<<endl;
	return sum;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int temp;
		unordered_map<int,int> freq;
		for(int i=0;i<n;i++)
			cin>>temp,freq[temp]++;
		// int ans = 0;
		for(auto it:freq)
		{
			if(it.second>0)
			{
				int sod = sumofDiv(it.first);
				if(freq.count(sod)>0 && sumofDiv(sod)==it.first)
					it.second--,freq[sod]--,cout<<it.first<<" "<<sod<<endl;
			}
		}
		//cout<<ans<<endl;
	}
	return 0;
}