#include <bits/stdc++.h>
using namespace std;

bool placeCows(long * a, int n, int c, long x){
    int placed = 1;
    long lastLoc = a[0];
    for(int i = 1; i < n; ++i){
        if(a[i] - lastLoc >= x){
            if(++placed == c){
                return true;
            }
            lastLoc = a[i];
        }
    }
    return false;
}

int main() {
	int t, c, n;
	cin>>t;
	while(t--){
		cin>>n>>c;
		long a[n];
		for(int i = 0; i < n; ++i){
			cin>>a[i];
		}
        if(c == 2){
            cout<<a[n-1] - a[0]<<endl;
            continue;
        }
        if(c == n){
            cout<<1<<endl;
            continue;
        }
        sort(a, a+n);
        long l = 0, r = a[n-1] - a[0] + 1, m;
        while(r > l+1){
            m = l + (r-l)/2;
            if(placeCows(a, n, c, m)){
                l = m;
            }
            else{
                r = m;
            }
        }
        cout<<l<<endl;
	}
	return 0;
}
