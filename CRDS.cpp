#include <bits/stdc++.h>
#define MOD 1000007

using namespace std;

long long dp[1000000] = {0};

long long count_cards(int N){

	if(N == 0)	return 0;

	if(dp[N] != 0)	return dp[N];

	dp[N] = (count_cards(N-1) + 3*N - 1) % MOD;

	return dp[N];
}

int main(){

	ios::sync_with_stdio(false);

	int T, N;

	cin>>T;

	while(T--){

		cin>>N;
		//cout<<N<<endl;
		cout<<count_cards(N)<<endl;

	}

	return 0;
}
