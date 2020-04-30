// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
/*You are required to complete this method*/

int maxLen(int arr[], int n) {
		for(int i=0;i<n;i++)
			if(arr[i]==0)
				arr[i]=-1;
        for(int i=1;i<n;i++)
        	arr[i]=arr[i]+arr[i-1];
        unordered_map<int,int> hash(n);
        int mx=0;
        // for(int i=0;i<n;i++)
        // 	cout<<arr[i]<<" ";
        // cout<<endl;
        hash[0]=-1;
        for(int i=0;i<n;i++)
        	if(hash.find(arr[i])==hash.end())
        		hash[arr[i]]=i;
        	else
        		mx = max(mx,i-hash[arr[i]]);
        return mx;
}