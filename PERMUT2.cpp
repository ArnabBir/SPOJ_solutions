#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	
	int n;
	
	while(true){
	    
	    cin>>n;
	    if(n == 0)  break;
	    
	    int x[n+1], y[n+1];
	    bool amb = false;
	    
	    for(int i = 1; i <= n; ++i){
	        
	        cin>>x[i];
	        y[x[i]] = i;
	    }
	    
	    //for(int i = 1; i <= n; ++i) cout<<x[i]<<" "<<y[i]<<endl;
	    
	    for(int i = 1; i <= n; ++i){
	        
	        if(x[i] != y[i]){
	            
	            amb = true;
	            break;
	        }
	    }
	    
	    if(amb) cout<<"not ambiguous"<<endl;
	    else    cout<<"ambiguous"<<endl;
	}
	
	return 0;
}
