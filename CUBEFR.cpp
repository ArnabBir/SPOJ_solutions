#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T, n, sum = 0, t = 1;
	cin>>T;
	vector<bool> v(1000001, true);
	vector<int> op(1000001);
	for(int i = 2; i < 100; ++i) {
	    int cube = i*i*i;
	    int x = cube;
	    while(x <= 1000000) {
	        v[x] = false;
	        x += cube;
	    }
	}
	op[1] = v[1];
	for(int i = 2; i <= 1000000; ++i) {
	    op[i] = op[i-1] + (int)v[i];
	}
	while(t<=T) {
	    cin>>n;
	    if(!v[n])    cout<<"Case "<<t++<<": "<<"Not Cube Free"<<endl;
	    else    cout<<"Case "<<t++<<": "<<op[n]<<endl;
	}
	return 0;
}
