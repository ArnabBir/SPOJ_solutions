#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, x, y, p;
	cin>>t;
	while(t--) {
	    cin>>x>>y;
	    p = 0;
	    if(x == y) {
	        p = 2*x - x%2;
	    }
	    else if(y == x-2) {
	        p = 2*x-x%2-2;
	    }
	    else {
	        cout<<"No Number"<<endl;
	        continue;
	    }
	    cout<<p<<endl;
	}
	return 0;
}
