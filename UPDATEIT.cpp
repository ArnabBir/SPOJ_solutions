#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int t, n, u, q, l, r, val, x;
	cin>>t;
	while(t--) {
		cin>>n>>u;
		vector<int> v(n+1, 0);
		while(u--) {
			cin>>l>>r>>val;
			v[l] += val;
			v[r+1] -= val;
		}

		for(int i = 1; i < n; ++i) {
			v[i] += v[i-1];
		}

		cin>>q;
		while(q--) {
			cin>>x;
			cout<<v[x]<<endl;
		}
	}

	return 0;
}
