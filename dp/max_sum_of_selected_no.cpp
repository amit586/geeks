#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int maxSum(unordered_map<int,int> &m , vector<int> &v,int n)
//int maxSum(unordered_map<int,int> &m , vector<int> &v,int n,int sum)
{
	// if(n<0)
	// 	return sum;
	// else if(m[v[n]]<=0)
	// 	return maxSum(m,v,n-1,sum);
	// else;
	// {
	// 	int x1 = maxSum(m,v,n-1,sum);
	// 	int count1 = m[v[n]+1],count2 = m[v[n]-1];
	// 	m[v[n]]--;
	// 	m[v[n]-1]=0;
	// 	m[v[n]+1]=0;
	// 	int x2 = maxSum(m,v,n-1,sum+v[n]);
	// 	m[v[n]]++;
	// 	m[v[n]-1] = count2;
	// 	m[v[n]+1] = count1;
	// 	return max(x1,x2);
	// }

	int maximum = *max_element(v.begin(),v.end());
	for(int i=2;i<=maximum;i++)
	{
		m[i] = max(m[i-1],m[i-2]+m[i]*i);
	}
	return m[maximum];

}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		unordered_map<int,int> m;
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			m[v[i]]++;
		}
		cout<<maxSum(m,v,n)<<endl;
		
	}
	return 0;
}
