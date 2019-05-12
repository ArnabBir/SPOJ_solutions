#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	cin>>n;
	int rootn = (int)sqrt(n);
	for(int i = 1; i <= rootn; ++i) {
	    ans += floor(n/i) - i + 1;
	}
	cout<<ans<<endl;
	return 0;
}
