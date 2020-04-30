#include <bits/stdc++.h>
#define ll long long
#define	x(p) get<0>(p)
#define y(p) get<1>(p)
#define e(p) get<2>(p)

using namespace std;
typedef tuple<int,int,bool> rect;

bool comp(const rect &p1,const rect &p2)
{
	return x(p1)<x(p2);
}

ll area(vector<rect> &pnts,int n)
{
	sort(pnts.begin(),pnts.end(),comp);
	map<int,pair<int,bool>> m;
	m.insert({y(pnts),{x(pnts),e(pnts)}});
	rect prev = pnts[0];

	for(int i=1;i<n;i++)
	{
		if()
	}
	
}

class event{
public:
	int ind;
	bool type;
	event(int ind,int type):ind(ind),type(type){};

};

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	vector<rect> pnts(2*n);
	for(int i=0;i<n;i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>x2;
		pnts[2*i]=make_tuple(x1,y1,0);
		pnts[2*i+1]=make_tuple(x2,y2,1);
	}

	cout<<area(pnts,n)<<endl;
	return 0;
}