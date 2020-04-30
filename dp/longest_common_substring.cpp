#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int max(int a,int b,int c)
{
	return max(a,max(b,c));
}

int LCsubstring(const string &X,const string &Y,int l1,int l2)
{
	// if(l1<=0 || l2<=0)
	// 	return 0;
	// else
	// {
	// 	int count=0;
	// 	while(str1[l1-1]==str2[l2-1] && l1>0 && l2>0)
	// 	{
	// 		count++;
	// 		l1--;
	// 		l2--;
	// 	}
	// 	return max(count,LCsubstring(str1,str2,l1-1,l2),LCsubstring(str1,str2,l1,l2-1));
	// }

	// vector<vector<int>> dp(l2+1,vector<int> (l1+1,0));
	// int mx=0;
	// for(int i=0;i<=l2;i++)
	// {
	// 	for(int j=0;j<=l1;j++)
	// 	{
	// 		if(i==0 || j==0)
	// 			dp[i][j]=0;
	// 		else if(str1[i-1]==str1[j-1])
	// 		{
	// 			dp[i][j] = dp[i-1][j-1]+1;
	// 			mx = max(dp[i][j],mx);
	// 		}
	// 		else
	// 			dp[i][j]=0;
	// 	}
	// }

	int m = l1;
	int n = l2;
    vector<vector<int>> LCSuff(m+1,vector<int> (n+1)); 
    int result = 0;  // To store length of the  
                     // longest common substring 
  
    /* Following steps build LCSuff[m+1][n+1] in 
        bottom up fashion. */
    for (int i=0; i<=m; i++) 
    { 
       for(int j=0;j<=n;j++)
       {
       		 if (i == 0 || j == 0) 
                LCSuff[i][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
            { 
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
                result = max(result, LCSuff[i][j]); 
            } 
            else LCSuff[i][j] = 0; 
       } 
    } 
    return result; 

}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int l1,l2;
		cin>>l1>>l2;
		string str1,str2;
		cin>>str1>>str2;

		cout<<LCsubstring(str1,str2,l1,l2)<<endl;	
		
	}
	return 0;
}
