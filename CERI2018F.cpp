#include <iostream>

using namespace std;

long long pow_rec(long long m, long long e, long long n){
    
    if(e == 1)  return m % n;
    if(e == 0)	return 1;
    
    long long product = pow_rec(m, e/2, n)  % n;
    
    if(e%2){
        return (((product * product) % n) * m) % n;
    }
    else    return (product * product) % n;
}

int main() {
	
	ios::sync_with_stdio(false);
	
	int t;
	long long n, e, m;
	
	cin>>t;
	
	while(t--){
	    
	    cin>>n>>e>>m;
	    
	    cout<<pow_rec(m, e, n)<<endl;
	}
	
	return 0;
}
