#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t, n;
	string s;
	cin>>t;
	unordered_map<string, int> um;
	string combo[8] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
	while(t--) {
	    cin>>n;
	    cin>>s;
	    for(int i = 0; i < 8; ++i)  um[combo[i]] = 0;
	    for(int i = 0; i < 38; ++i) {
	        ++um[s.substr(i, 3)];
	    }
	    string result = to_string(n);
	    for(int i = 0; i < 8; ++i) {
	        result += " " + to_string(um[combo[i]]);
	    }
	    cout<<result<<endl;
	}
	return 0;
}
