#include <bits/stdc++.h>
using namespace std;

struct customHash{
	size_t operator()(uint64_t x) const{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x+FIXED_RANDOM;
	}
};

struct customEqual{
	bool operator()(uint64_t  &x,uint64_t &y) const{
		return x==y;
	}
};

int main(int argc, char const *argv[])
{
	unordered_set<int,customHash,customEqual>s;
	return 0;
}