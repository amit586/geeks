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
        sort(arr,arr+n);
        int even = n/2;
        int odd = n-even;
        //cout<<"odd "<<odd<<" even "<<even<<endl;

        int arr1[odd];
        int arr2[even];
        //cout<<arr[0]<<endl;

        for(int i=0;i<odd;i++)
        {
           arr1[i]=arr[i];
        }

        for(int i=odd;i<n;i++)
            arr2[i-odd]=arr[i];
        
        // cout<<"odd : ";
        // for(int i=0;i<odd;i++)
        //     cout<<arr1[i]<<" ";
        // cout<<endl;

        // cout<<"even : ";
        // for(int i=0;i<even;i++)
        //     cout<<arr2[i]<<" ";
        // cout<<endl;
        int i=0;
        while(i<n/2)
        {
            //cout<<"i "<<i<<" arr1 "<<arr1[i]<<" arr2 "<<arr2[i]<<endl;
            arr[2*i]=arr1[i];
            arr[2*i+1]=arr2[i];
            i++;
        }
        if(n%2==1)
            arr[n-1]=arr1[odd-1];
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;

    }
	return 0;
}