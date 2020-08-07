#include<bits/stdc++.h>
using namespace std;

long long int arr1[1000000],arr2[1000000];

int main() {
    int tc;
    cin>>tc;
    while(tc--)
    {
       
        int n1,n2;
        cin>>n1>>n2;
        for(int i=0;i<n1;i++)
            cin>>arr1[i];
        for(int i=0;i<n2;i++)
            cin>>arr2[i];

        int ptr1 = n1-1;
        int ptr2 = 0;
        while(ptr1>0 and ptr2<n2)
        {
            if(arr1[ptr1]>arr2[ptr2])
                swap(arr1[ptr1],arr2[ptr2]),ptr2++,ptr1--;
            else 
                break;
        }

        sort(arr1,arr1+n1);
        sort(arr2,arr2+n2);
        for(int i=0;i<n1;i++)
            cout<<arr1[i]<<" ";
        for(int i=0;i<n2;i++)
            cout<<arr2[i]<<" ";
        cout<<endl;     
    }
    return 0;
}