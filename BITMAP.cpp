#include <bits/stdc++.h>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int t, n, m, l, p, q, r;

	cin>>t;

	while(t--){

		cin>>n>>m;

		string s[n];
		int dp[n][m];

		for(int i = 0; i < n; ++i){

			cin>>s[i];
		}

		for(int i = 0; i < n; ++i){

			for(int j = 0; j < m; ++j){

				if(s[i][j] == '1'){

					dp[i][j] = 0;
				}
				else{

					dp[i][j] = INT_MAX;
				}
			}
		}

		for(int i = 0; i < n; ++i){		// IN-OUT Dyanamic Programming
		
			for(int j = 0; j < m; ++j){
				//cout<<"HELLO"<<endl;
				if(s[i][j] == '0'){
				
					p = (i - 1 >= 0 && dp[i-1][j] != INT_MAX) ? (dp[i-1][j] + 1) : INT_MAX;
					q = (j - 1 >= 0 && dp[i][j-1] != INT_MAX) ? (dp[i][j-1] + 1) : INT_MAX;
					r = (i - 1 >= 0 && j - 1 >= 0 && dp[i-1][j-1] != INT_MAX) ? (dp[i-1][j-1] + 2) : INT_MAX;
				}

				dp[i][j] = min( dp[i][j], min( min(p, q), r));
			}
		}

		for(int i = n-1; i >= 0; --i){		// IN-OUT Dyanamic Programming
		
			for(int j = m-1; j >= 0; --j){

				if(s[i][j] == '0'){
				
					p = (i + 1 < n && dp[i+1][j] != INT_MAX) ? (dp[i+1][j] + 1) : INT_MAX;
					q = (j + 1 < m && dp[i][j+1] != INT_MAX) ? (dp[i][j+1] + 1) : INT_MAX;
					r = (i + 1 < n && j + 1 < m && dp[i+1][j+1] != INT_MAX) ? (dp[i+1][j+1] + 2) : INT_MAX;
				}

				dp[i][j] = min( dp[i][j], min( min(p, q), r));
			}
		}



		for(int i = 0; i < n; ++i){
		
			for(int j = 0; j < m; ++j){

				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}
