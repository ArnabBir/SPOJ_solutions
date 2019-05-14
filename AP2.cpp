#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
	
	int t;
	long long int x, y, z, temp, a, n, d;
	cin>>t;
	while(t--) {
	    cin>>x>>y>>z;
	    temp = y-x;
	    n = 2*z/(x+y);
	    d = (y-x)/(n-5);
	    a = x - 2*d;
	    cout<<n<<endl;
	    for(int i = 1; i <= n; ++i) {
	        cout<<a+(i-1)*d<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
