#include <bits/stdc++.h>

using namespace std;

int main() {

	int t, n, carry;
	cin>>t;
	string exp;

	while(t--) {
		cin>>n;
		vector<int> result;
		result.push_back(1);
		for(int i = 2; i <= n; ++i) {
			carry = 0;
			for(int j = 0; j < result.size(); ++j) {
				int prod = i * result[j] + carry;
				result[j] = prod % 10;
				carry = prod / 10;
			}
			while(carry) {
				result.push_back(carry % 10);
				carry /= 10;
			}
		}
		for(int i = result.size()-1; i >= 0; --i) {
			cout<<result[i];
		}
		cout<<endl;
	}

	return 0;
}
