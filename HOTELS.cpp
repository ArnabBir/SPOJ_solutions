#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
	int n;
	long long m, sum = 0, maxSum = -1;
	cin>>n>>m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
	    cin>>v[i];
	}
	int l = 0, r = 0;
	while(r < n) {
	    while(sum + v[r] > m) {
	        sum = sum - v[l++];
	    }
	    sum += v[r];
	    maxSum = max(sum, maxSum);
        ++r;
	}
	cout<<maxSum<<endl;
	
	return 0;
}
