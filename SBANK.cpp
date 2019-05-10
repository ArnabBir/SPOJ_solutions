#include <bits/stdc++.h>
using namespace std;

int main() {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t, n, count, x = 0;
    string s;
    cin>>t;
    while(x++ < t) {
        cin>>n;
        //getline(cin, s);
        cin.ignore();
        vector<string> v(n);
        for(int i = 0; i < n; ++i) {
            getline(cin, v[i]);
        }
        getline(cin, s);
        //cin.ignore();
        sort(v.begin(), v.end());
        count = 1;
        for(int i = 1; i < n; ++i) {
            if(v[i-1] == v[i]) {
                ++count;
            }
            else {
                cout<<v[i-1]<<" "<<count<<endl;
                count = 1;
            }
        }
        cout<<v[n-1]<<" "<<count<<"\n\n";
    }
	return 0;
}
