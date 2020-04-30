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
		std::vector<int> v(n);
		unordered_map<int,int> freq;
		freq[0]=0;
		vector<int> topk(k+1,0);
		for(int i=0;i<n;i++)
			cin>>v[i];

		for(int i=0;i<n;i++)
		{
			freq[v[i]]++;
			topk[k]=v[i];
			int loc=k;
			for(int j=k-1;j>=0;j--)
				if(topk[j]==v[i])
					loc=j;

			for(int j=loc-1;j>=0;j--)
				if(freq[topk[j+1]]>freq[topk[j]] || (freq[topk[j+1]]==freq[topk[j]] && topk[j+1]<topk[j]))
					swap(topk[j+1],topk[j]);
			for(int j=0;j<min(i+1,k);j++)
				cout<<topk[j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

//57 44 57 44 57 92 28 44 57 28 44 57 28 44 57 28 37 44 28 33 37 28 33 37 28 33 37 28 29 33 28 29 33 8 28 29 8 28 29 8 22 28 
//57 44 57 44 57 92 28 44 57 28 44 57 28 44 57 28 37 44 28 33 37 28 33 37 28 33 37 28 29 33 28 29 33 8 28 29 8 28 29 8 22 28 
