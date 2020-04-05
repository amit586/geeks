#include <bits/stdc++.h>
using namespace std;

long long index(long long i)
{
    return i-2;
}

long long nextP(long long p,bool vis[],long long n)
{
    for(long long i=p+1;i<=n;i++)
    {
        if(!vis[index(i)])
            return i;
    }
}

void solve(long long arr[],long long n)
{
    bool vis[n]={0};
    long long p=2;
    while(p*p<=n)
    {
        for(long long i=p;p*i<=n;i++)
        {
            vis[index(p*i)]=true;
        }
        p = nextP(p,vis,n);
    }
    
    for(int i=2;i<=n;i++)
            if(!vis[index(i)])
                cout<<i<<" ";
    cout<<endl;
}

int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    long long n;
	    cin>>n;
	    long long arr[n];
	    for(long i=0;i<=n;i++)
            arr[i]=i+2;
            
        solve(arr,n);
	}
	return 0;
}