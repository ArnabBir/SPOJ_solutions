#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n;
	cin>>n;
	if(n%10) {
	    cout<<1<<endl;
	    cout<<n%10<<endl;
	}
	else {
	    cout<<2<<endl;
	}
	return 0;
}
