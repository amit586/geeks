#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
int main()
{
    int n=100;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
        m[i]++;
    vector<int> v;
    auto start = high_resolution_clock::now();
    for(auto it:m)
        it.second++;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<<duration.count()<<endl;
}