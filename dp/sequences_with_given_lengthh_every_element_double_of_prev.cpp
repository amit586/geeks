#include <bits/stdc++.h>
using namespace std;

void print(vector <int> &solution)
{
	for(int i=0;i<solution.size();i++)
		cout<<solution[i]<<" ";
	cout<<endl;
}

void findSequence(int n,int m ,std::vector<int> &sol)
{	
	if (m < n) 
        return ; 
    if (n == 0)
    { 
        print(sol);
        return; 
	}
	findSequence(n,m-1,sol);
	sol.push_back(m);
	findSequence(n-1,m/2,sol);
	sol.pop_back();
}

int countSubsequence(int n,int m)
{
	// if(m<n)
	// 	return 0;
	// if(n==0)
	// 	return 1;
	// return countSubsequence(n,m-1)+countSubsequence(n-1,m/2);

	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<=m;i++)
		dp[0][i]=1;

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i>j)
				continue;
			else dp[i][j]=dp[i][j-1]+dp[i-1][j/2];
		}
	}
	return dp[n][m];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>m>>n;
		//vector <int> sol;
		//findSequence(n,m,sol);
		cout<<countSubsequence(n,m);
	}
	return 0;
}