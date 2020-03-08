#include <iostream>
#include<algorithm>
using namespace std;

class box
{
public:
    int ai,aj;
};

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n,nt;
	    cin>>nt>>n;
	    box arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i].ai>>arr[i].aj;
	    }
	    
	    sort(arr,arr+n,[](box b1,box b2)->bool
	    {
	        return b1.aj<b2.aj;
	    });
	    

	    for(int i=0;i<n;i++)
	    {
	        cout<<arr[i].ai<<" "<<arr[i].aj<<endl;
	    }
	    int plates_picked=0,coins=0;
	    int i=n-1;
	    
	    while((plates_picked+arr[i].ai<nt) && i>=0)
	    {
	            plates_picked+=arr[i].ai;
	            coins+=arr[i].ai*arr[i].aj;
	            i--;
	    }
	    if(i>=0 && plates_picked<nt)
	    {
	        coins+=arr[i].aj*(nt-plates_picked);
	    }
	    cout<<coins<<endl;
	    
	}
	return 0;
}