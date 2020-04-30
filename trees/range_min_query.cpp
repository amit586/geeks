// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends
/* The functions which 
builds the segment tree */

int constructSTUtil(int arr[],int ss,int se,int *st,int si)
{
	if(ss==se)
		{st[si]=arr[ss];return st[si];};
	int mid = (se+ss)/2;
	st[si]=min(constructSTUtil(arr,ss,mid,st,2*si+1),constructSTUtil(arr,mid+1,se,st,2*si+2));
	return st[si];
}

int *constructST(int arr[],int n)
{
	int mx_size=2*pow(2,(int)ceil(log2(n)))-1;
	int *st = new int[mx_size];
	constructSTUtil(arr,0,n-1,st,0);
	return st; 
}

int RMQutil(int st[],int ss,int se,int qs,int qe,int si)
{
    if(qe<ss || se<qs)
    	return INT_MAX;
    if(qs<=ss && se<=qe)
    	return st[si];
    int mid=(ss+se)/2;
    return min(RMQutil(st,ss,mid,qs,qe,2*si+1),RMQutil(st,mid+1,se,qs,qe,2*si+2));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    return RMQutil(st,0,n-1,a,b,0);
}