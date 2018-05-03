#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	
	int t, n;
	
	cin>>t;
	
	while(t--){
	    
	    cin>>n;
	    
	    int x[n], y[n];
	    long sum_bond = 0;
	    
	    for(int i = 0; i < n; ++i){
	        
	        cin>>x[i];
	    }
	    
	    for(int i = 0; i < n; ++i){
	        
	        cin>>y[i];
	    }
	    
	    sort(x, x + n);
	    sort(y, y + n);
	    
	    for(int i = 0; i < n; ++i){
	        
	        sum_bond += x[i] * y[i];
	    }
	    
	    cout<<sum_bond<<endl;
	}
	
	return 0;
}
