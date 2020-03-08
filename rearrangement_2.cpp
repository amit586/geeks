#include <bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b=temp;
}

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
	    vector <int> pos,neg;
	    for(int i = 0;i<n;i++)
	    {
	        if(arr[i]>=0)
	            pos.push_back(arr[i]);
	        else 
	            neg.push_back(arr[i]);
	    }
	    vector <int> ans;
	    int i=0,j=0;
	    while(i<pos.size() && j<neg.size())
	    {   
	        ans.push_back(pos[i]);
	        i++;
	        ans.push_back(neg[j]);
	        j++;
	    }
	    while(j<neg.size())
	    {
	        ans.push_back(neg[j]);
	        j++;
	    }
	    while(i<pos.size())
	    {
	        ans.push_back(pos[i]);
	        i++;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}