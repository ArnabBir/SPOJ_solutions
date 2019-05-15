#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int getLCS(string s1, string s2, int n) {
    
    int dp[n+1][n+1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+ (s1[i-1] == s2[j-1]));
        }
    }
    return dp[n][n];
}

int main() {
	
	int t, n;
	string s;
	cin>>t;
	while(t--) {
	    cin>>s;
	    n = s.length();
	    stack<int> s1, s2;
	    if(n < 2) {
	        cout<<0<<endl;
	    }
	    else {
	        string revs = s;
	        reverse(revs.begin(), revs.end());
	        
	        cout<<n - getLCS(s, revs, n)<<endl;
	    }
	}
	return 0;
}
