#include <bits/stdc++.h>

using namespace std;

int main() {

	int t, n, k, l, count;
	cin>>t;

	while(t--) {
		cin>>n;
		int a[n+1][n+1];
		memset(a, 0, sizeof a);
		for(int i = 1; i <= n; ++i) {
			cin>>k;
			for(int j = 0; j < k; ++j) {
				cin>>l;
				a[l][i] = 1;
			}
		}
		for(int k = 1; k <= n; ++k) {
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= n; ++j) {
				    if(i != j)  {
				        a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
				    }
				}
			}
		}
        int result = 0;
		for(int i = 1; i <= n; ++i) {
			count = 0;
			for(int j = 1; j <= n; ++j) {
				if(i != j)  count += a[i][j];
			}
			if(count == n-1) ++result;
		}
		cout<<result<<endl;
	}

	return 0;
}
