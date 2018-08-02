#include <bits/stdc++.h>
using namespace std;

int main() {

	int t, sum;
	string m, n, ans;
	cin>>t;
	while(t--) {
	    char temp, carry = '0', mi, ni;
	    cin>>m>>n;
	    reverse(m.begin(), m.end());
	    reverse(n.begin(), n.end());
	    int sum = stoi(m) + stoi(n);
	    while(sum % 10 == 0)  sum /= 10;
	    ans = to_string(sum);
	    reverse(ans.begin(), ans.end());
	    cout<<ans<<endl;
	    
	}
	return 0;
}
