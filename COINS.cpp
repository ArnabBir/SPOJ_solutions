// http://www.spoj.com/problems/COINS/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<int, ll> dp;


ll countCoins(int n){
    if(n == 0)  return 0;
    if(dp[n] != 0)  return dp[n];
    ll temp = countCoins(n/2) + countCoins(n/3) + countCoins(n/4);
    dp[n] = max((ll)n, temp);
    return dp[n];
}

int main() {

    dp[1] = 1;
    dp[2] = 2;
    int n;
    while(scanf("%d", &n) == 1){
        cout<<countCoins(n)<<endl;
    }
	return 0;
}
