#include <bits/stdc++.h>

using namespace std;

int main(){

	int T, h, w;
	long long opt;

	cin>>T;

	while(T--){

		cin>>h>>w;

		int a[h][w];

		long long dp[h][w] = {0};

		for(int i = 0; i < h; ++i){

			for(int j = 0; j < w; ++j){

				cin>>a[i][j];
			}
		}

		for(int j = 0; j < w; ++j){

			dp[0][j] = a[0][j];
		}

		for(int i = 1; i < h; ++i){

			for(int j = 0; j < w; ++j){

				if(j > 0 && j < w-1){

					dp[i][j] = a[i][j] + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
				}
				else if(j == w-1){

					dp[i][j] = a[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
				}
				else if(j == 0){

					dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
				}
			}
		}

		opt = dp[h-1][0];

		for(int j = 1; j < w; ++j)	opt = max(opt, dp[h-1][j]);

		cout<<opt<<endl;

	}

	return 0;
}
