#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n, t, x, accum;
	cin>>t;
	while(t--) {
	    cin>>n;
	    accum = 0;
	    for(int i = 0; i < n; ++i)  {
	        cin>>x;
	        accum = ((accum % n) + (x % n))%n;
	    }
	    cout<<((accum % n) ? "NO" : "YES")<<endl;
	}
	return 0;
}
