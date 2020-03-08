#include <bits/stdc++.h>
using namespace std;

class area
{
public:
	int x,y;
	area(int a,int b)
	{
		x = a;
		y= b;
	}	
};

int max(int a,int b,int c)
{
	return max(a,max(b,c));
}

int maxSurvival(int a,int b,area X,area Y,area Z, std::map<pair<int,int>, int> &memo,int choice)
{
	if(a<=0 || b<=0)
		return 0;
	auto it = memo.find(make_pair(a,b));
	if(it!=memo.end())
		return it->second;
	int temp;
	switch(choice)
	{
		case 1:temp  = 1 + max(maxSurvival(a+Y.x,b+Y.y,X,Y,Z,memo,2),maxSurvival(a+Z.x,b+Z.y,X,Y,Z,memo,3));
				memo[make_pair(a,b)]=temp;
				break;
		case 2: temp  = 1 + max(maxSurvival(a+X.x,b+X.y,X,Y,Z,memo,1),maxSurvival(a+Z.x,b+Z.y,X,Y,Z,memo,3));
				memo[make_pair(a,b)]=temp;
				break;
		case 3: temp  = 1 + max(maxSurvival(a+X.x,b+X.y,X,Y,Z,memo,1),maxSurvival(a+Y.x,b+Y.y,X,Y,Z,memo,2));
				memo[make_pair(a,b)]=temp;
				break;
	}
	return temp;
}

int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	area X(3,2),Y(-5,-10),Z(-20,5);
	std::map<pair<int,int>,int> memo;
	cout<<max(maxSurvival(a+X.x,b+X.y,X,Y,Z,memo,1),maxSurvival(a+Y.x,b+Y.y,X,Y,Z,memo,2),maxSurvival(a+Z.x,b+Z.y,X,Y,Z,memo,3))<<endl;
	return 0;
}