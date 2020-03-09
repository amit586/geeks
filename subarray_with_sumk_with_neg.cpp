#include <iostream>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int arr[n+1];
	    arr[0] = 0;
	    for (int i=1; i < n+1; i++) {
	        int tmp;
	        cin >> tmp;
	        arr[i] = tmp + arr[i-1];
	    }
	    int s;
	    cin >> s;
	    
	    int count = 0;
	    
	    map<int, int> m;
	    m[0] = 1;
	    for (int i=1; i < n+1; i++) {
	        if (m.find(arr[i]-s) != m.end()) {
	            count += m[arr[i]-s];
	        }
	        if (m.find(arr[i]) == m.end()) {
	            m[arr[i]] = 0;
	        }
	        m[arr[i]] ++;
	    }
	    cout << count << "\n";
	}
	return 0;
}
