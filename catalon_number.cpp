#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 

#define MAX 1001
using namespace std;
using boost::multiprecision::cpp_int; 



cpp_int dp[MAX];


cpp_int catalon (int n)
{

    if(dp[n]!=0)
        return dp[n];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=5;
    dp[4]=14;
    cpp_int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=catalon(i)*catalon(n-i-1);
    }
    dp[n]=sum;
    return sum;
 }

int main() {
	int t;
	cin>>t;
	int arr[t],mx=INT_MIN;
	for(int i=0;i<t;i++)
	{
	    cin>>arr[i];
	    mx = max(mx,arr[i]);
	}
	catalon(mx);
	for(int i=0;i<t;i++)
	{
	    cout<<dp[arr[i]]<<endl;
	}
	    
	      
	return 0;
}