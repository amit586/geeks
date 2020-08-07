#include <bits/stdc++.h>

#define mod     1000000007
#define pi      3.1415926535897932384626433832795
#define fio     ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define ll      long long
#define ld      long double
#define pb      push_back
#define all(x)  x.begin(),x.end()
#define f       first
#define s       second
#define int     ll

using namespace std;

class train{
public:
	int arrival,departure;
};

main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		std::vector<train> t(n);
		for(int i=0;i<n;++i)	cin>>t[i].arrival;
		for(int i=0;i<n;i++)	cin>>t[i].departure;
		sort(all(t),[](const train ta,const train tb)->bool{
			if(ta.arrival==tb.arrival)
				return ta.departure<tb.departure;
			return ta.arrival<tb.arrival;
		});

		priority_queue<int,vector<int>,greater<int>>pq;

		int mx_platform = 0;
		for(int i=0;i<n;i++)
		{
			while(!pq.empty() and pq.top()<=t[i].arrival)
				pq.pop();
			pq.push(t[i].departure);
			mx_platform = max(mx_platform,(int)pq.size());
		}
		cout<<mx_platform<<endl;
		
	}
	return 0;
}
