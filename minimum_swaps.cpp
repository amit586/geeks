#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    int k;
	    cin>>k;
	    
	    int window_size=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<=k)
	            window_size++;
	    }
	    
	    //cout<<"window size : "<<window_size<<endl;
	    int bad=0;
	    for(int i=0;i<window_size;i++)
	    {
	       if(arr[i]>k)
	        bad++;
	    }
	   
	    int min_swap=bad,last = 0;
	    for(int i=window_size;i<n;i++)
	    {
	        if(arr[i]>k)
	            bad++;
	        if(arr[last]>k)
	            bad--;
	        last++;
	        
	        if(bad<min_swap)
	            min_swap = bad;
	    }
	    cout<<min_swap<<endl;
	}
	return 0;
}