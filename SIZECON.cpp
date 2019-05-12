#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long long int t, n, sum = 0;
	cin>>t;
	while(t--) {
	    cin>>n;
	    if(n > 0)   sum += n;
	}
	cout<<sum<<endl;
	return 0;
}
