#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000] = {-1};
int sum[1000][1000] = {-1};
int a[1000] = {0};

int arraySum(int l, int r) {

	if(l > r)	return 0;
    if(sum[l][r] != -1)   return sum[l][r];
    sum[l][r] = accumulate(a + l, a + r + 1, 0) % 100;
    return sum[l][r];
}

// int arraySum(int l, int r) {

// 	if(l > r)	return 0;
//     return accumulate(a + l, a + r + 1, 0) % 100;
// }

int getMinSmoke(int l, int r) {

    if(l >= r)  return 0;
    if(dp[l][r] != -1)  return dp[l][r];
    dp[l][r] = INT_MAX;
    for(int i = l; i <= r; ++i) {
        dp[l][r] = min(dp[l][r], getMinSmoke(l, i) + (getMinSmoke(i+1, r) + arraySum(l, i) * arraySum(i+1, r)));
    }
    return dp[l][r];
}

int main() {
    
    int n;
    while(scanf("%d", &n) != -1) {
    	memset(dp, -1, sizeof dp);
    	memset(sum, -1, sizeof sum);
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        cout<<getMinSmoke(0, n-1)<<endl;
    }
    return 0;
}
