#include <bits/stdc++.h>
using namespace std;
bool dp[10000][10000];


int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    string str;
	    cin>>str;
	    int start,end,mxLen=1,mxIndex=0,n = str.size();
	 	
	 	
	 	for(int i=0;i<n;i++)
            dp[i][i]=1;


        for(int i=0;i<n-1;i++)
            if(str[i]==str[i+1])
                dp[i][i+1] = 1,mxLen=2,mxIndex=i;
            else
                dp[i][i+1]=0;
	 	

	 	for(int i=2;i<str.size();i++)
	    {
	        for(int j=0;j<str.size();j++)
	            {
	                start = j;
	                end =j+i;
	                if(str[start]==str[end] && dp[start+1][end-1])
	                {
	                    dp[start][end]=1;
	                    if(end-start+1>mxLen)
	                        mxLen = end-start+1,mxIndex = start;
	                }
	                else 
	                    dp[start][end]=0;
	                
	            }
	    }
	   // cout<<mxIndex<<" "<<mxLen<<endl;
	    for(int i=mxIndex;i<mxIndex+mxLen;i++)
	        cout<<str[i];
	    cout<<endl;
	}
	return 0;
}