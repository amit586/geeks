#include <iostream>
#define P 1000000007
using namespace std;
unsigned long long dp[101]={0};
unsigned long long pairs(int n)
{
    if(dp[n]!=0)
        return dp[n];
    else
    {
        dp[n]=pairs(n-1)%P+((n-1)*pairs(n-2))%P;
        return dp[n];
    }
}


int main() {
    int t;
    cin>>t;
    int arr[t],mx=0;
    dp[0]=1;
    dp[1]=1;
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
        mx = max(mx,arr[i]);
    }
    pairs(mx);
    for(int i=0;i<t;i++)
        cout<<dp[arr[i]]%P<<endl;
    
	return 0;
}