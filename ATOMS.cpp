#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int p;
	long double n, k, m;
	cin>>p;
	while(p--) {
	    cin>>n>>k>>m;
	    if(m < n) {
	        cout<<0<<endl;
	    }
	    else cout<<floor(log(m/n) / log(k))<<endl;
	}
	return 0;
}
