#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		unordered_map<int,int> s;
		for(int i=0;i<n;i++)
			cin>>v[i],s[v[i]]++;
		int max_p = INT_MIN;
		// int p1=-1,p2=-1;
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=i+1;j<n;j++)
		// 	{
		// 		if(s.count(v[i]*v[j])>0 && v[i]*v[j]>max_p)
		// 			p1=v[i],p2=v[j],max_p=v[i]*v[j];
		// 	}
		// }
		// max_p!=INT_MIN?cout<<max_p<<endl:cout<<-1<<endl;

		//// ******** more efficient solution *********** ///
		sort(v.begin(), v.end());
		bool found=false;
		for(int i=n-1;i>=1;i--)
		{
			for(int j=0;j<i && v[j]<=sqrt(v[i]);j++)
			{
				if(v[i]%v[j]==0)
				{
					if((v[i]/v[j])==v[j] && (s[v[j]]>=2) && max_p<v[i])
						found=true,max_p=v[i];
					else if(s.count(v[i]/v[j])>0 &&(v[i]!=v[i]/v[j]) && max_p<v[i])
						found=true,max_p=v[i];
					else if(v[i]==v[i]/v[j] && s.count(v[i])>=2 && max_p<v[i])
						found=true,max_p=v[i];
					if(found)
						break;
				}
				if(found)
					break;
				
			}
		}
		found?cout<<max_p<<endl:cout<<-1<<endl;
	}
	return 0;
}