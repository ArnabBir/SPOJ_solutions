#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	unsigned long long int n, l, b, surplus, sqs;
	cin>>t;
	while(t--) {
	    cin>>n;
	    if(n < 4) {
	        cout<<0<<endl;
	        continue;
	    }
	    l = floor(sqrt(n/2));
	    if(2*l*(l+1) > n) {
	        --l;
	    }
	    surplus = n - 2*l*(l+1);
	    sqs = (l*l*(l+1)*(l+1))/4;
	    b = 0;
	    //cout<<n<<" : "<<surplus<<endl;
	    if(surplus >= 3) {
	        ++b;
	        surplus -= 3;
	        if(l > 1) {
	            while(surplus >= 2) {
	                ++b;
	                surplus -= 2;
	            }
	        }
	        else {
	            while(surplus >= 3) {
	                ++;
	                surplus -= 2;
	            }
	        }
	        sqs += ((l+1)*(l+2)*b*(b+1))/4 - (l*(l+1)*b*(b+1))/4;
	    }
	    cout<<sqs<<endl;
	}
	return 0;
}
