#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        int k1,k2;
        cin>>k1>>k2;
        k2--;
        k2 = min(n,k2);
        int sum=0;
        for(int i=k1;i<k2;i++)
            sum+=v[i];//,cout<<v[i]<<" "<<i<<endl;
        cout<<sum<<endl;
        
    }
	return 0;
}