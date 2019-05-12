#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, accum, avg, d;
	while(true) {
	    cin>>n;
	    if(n == -1) {
	        break;
	    }
	    vector<int> v(n);
	    for(int i = 0; i < n; ++i) {
	        cin>>v[i];
	    }
	    accum = accumulate(v.begin(), v.end(), 0);
	    if(accum % n) {
	        cout<<-1<<endl;
	    }
	    else {
	        avg = accum / n;
	        d = 0;
	        for(int i = 0; i < n; ++i) {
	            if(v[i] > avg) {
	                d += v[i] - avg;
	            }
	        }
	        cout<<d<<endl;
	    }
	}
	return 0;
}
