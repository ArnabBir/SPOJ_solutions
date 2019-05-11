#include <bits/stdc++.h>
using namespace std;

long long int dp[16] = {1, 1, 1, 4, 6, 19, 43, 120, 307, 866, 2336, 6588, 18373, 52119, 147700, 422016};

int main() {
    
    int t, n;
    cin>>t;
    for(int i = 0; i < t; ++i) {
        cin>>n;
        cout<<"Case #"<<i+1<<": "<<dp[n-1]<<endl;
    }
    return 0;
}
