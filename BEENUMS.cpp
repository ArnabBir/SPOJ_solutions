#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	
	ll n, k = 1, t = 0;
	set<ll> s;
	while(k < 1000000000) {
	    s.insert(k);
	    k += (++t) * 6;  
	}
	while(true) {
	    cin>>n;
	    if(n == -1) break;
	    if(s.find(n) != s.end()) {
	        cout<<"Y"<<endl;
	    }
	    else    cout<<"N"<<endl;
	}
	return 0;
}
