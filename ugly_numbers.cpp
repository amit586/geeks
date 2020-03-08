#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
long long dp[MAX];

long long min(long long a,long long b,long long c)
{
    long long arr[3];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    sort(arr,arr+3);
    return arr[0];
}


long long ugly(int n)
{
	if(dp[n]!=0)
		return dp[n];
    long long next_ugly=1;
    int i1,i2,i3;
    i1=i2=i3=0;
    dp[0]=1;
    long long next_2,next_3,next_5;
    for(int i=1;i<n;i++)
    {
        next_2= dp[i1]*2;
        next_3 = dp[i2]*3;
        next_5 = dp[i3]*5;
        next_ugly = min(next_2,next_3,next_5);
          
        if(next_ugly==next_2)
        {
            i1++;
            dp[i]=next_ugly;
        }
        if(next_ugly==next_3)
        {
            i2++;
            dp[i]=next_ugly;
        }
        if(next_ugly==next_5)
        {
            i3++;
            dp[i]=next_ugly;
        }
    }
    return next_ugly;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	   int n;
	    cin>>n;
	    cout<<ugly(n)<<endl;
	    
	}
	return 0;
}