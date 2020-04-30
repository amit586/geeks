// #include <bits/stdc++.h>
// #include <boost/functional/hash.hpp> 
// #define INF 1e5
// using namespace std;
// int main(int argc, char const *argv[])
// {
// 	int tc;
// 	cin>>tc;
// 	while(tc--)
// 	{
// 		int n;
// 		cin>>n;
// 		vector<pair<int,int>> v(n);
// 		unordered_map <pair<int,int> ,int,boost::hash<pair<int,int>>> lines;
		
// 		int x;
		
// 		for(int i=0;i<n;i++)
// 		{
// 			cin>>x;
// 			v[i]={x,0};
// 		}
// 		for (int i = 0; i < n; ++i)
// 			cin>>v[i].second;

// 		int mx=2;
// 		for(int i=0;i<n;i++)
// 		{
// 			int count=0;
// 			for(int j=i+1;j<n;j++)
// 			{
// 				if(point[i]==point[j])	
// 					count++;
// 				else
// 				{
// 					int x = point[i].first - point[j].first;
// 					int y = point[i].second-point[j].second;
// 				}
// 			}
// 		}
// 		cout<<mx<<endl;
// 	}
// 	return 0;
// }



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

int maxPoints(int X[],int Y[],int );              
int main() {
     
     int t;
     cin>>t;
     while(t--)
     {
        int n;
        cin>>n;
        int x[n];
        int y[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }


        for(int i=0;i<n;i++)
        {
            cin>>y[i];
        }

     
    cout << maxPoints(x,y,n) << endl;
     }
    
     
   
    return 0;
}// } Driver Code Ends
/*You are required to complete this method */
int maxPoints(int X[], int Y[],int N) {
     map<double,int> m;
     int INF = 1000000; 
     int global_mx=2;
     //cout<<N<<endl;
     for(int i=0;i<N;i++)
     {
         int overlap=0;
         int local_mx=0;
         for(int j=0;j<N;j++)
         {
            if(i!=j)
            {
                if(X[i]==X[j] && Y[i]==Y[j])
                    overlap++;
                else if(X[i]==X[j])
                    m[INF]++;
                else
                {
                    double slope = (Y[j]-Y[i]) / (double)(X[j]-X[i]);
                    m[slope]++;
                }
            }
        }
        //cout<<"overlap "<<overlap<<endl;
        for(auto it:m)
            local_mx = max(local_mx,1+it.second+overlap);//,cout<<"first "<<it.first<<" second "<<it.second<<endl;
        global_mx = max(local_mx,global_mx);
        m.clear();
        
     }
     return global_mx;
}