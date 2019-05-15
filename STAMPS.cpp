#include <bits/stdc++.h>
using namespace std;

bool comp(int x, int y) {
    return x > y;
}

int main() {
	
	int t, T, n, x, accum, cum;
	cin>>T;
	while(t++ < T) {
	    cout<<"Scenario #"<<t<<":\n";
	    cin>>x>>n;
	    accum = 0;
	    vector<int> v(n);
	    for(int i = 0; i < n; ++i) {
	        cin>>v[i];
	        accum += v[i];
	    }
	    if(x > accum) {
	        cout<<"impossible\n\n";
	    }
	    else if(x == accum) {
	        cout<<n<<endl;
	    }
	    else {
	        cum = 0;
	        sort(v.begin(), v.end(), comp);
	        for(int i = 0; i < n; ++i) {
	            cum += v[i];
	            if(cum >= x) {
	                cout<<i+1<<"\n\n";
	                break;
	            }
	        }
	    }
	}
	return 0;
}
