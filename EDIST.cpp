#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int T;
	string A, B;
	
	cin>>T;
	
	while(T--){
	    
	    cin>>A>>B;
	    
	    int dp[A.size()+1][B.size()+1] = {0};
	    
	    for(int i = 0; i <= A.size(); ++i){
	    
	        dp[i][0] = i;
	    }
	    
	    for(int j = 0; j <= B.size(); ++j){
	    
	        dp[0][j] = j;
	    }
	    
	    for(int i = 1; i <= A.size(); ++i){
	        
	        for(int j = 1; j <= B.size(); ++j){
	        
	            if(A[i-1] == B[j-1]){
	                
	                dp[i][j] = min( dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) + 1);
	            }
	            else {
	                
	                dp[i][j] = min( dp[i-1][j-1] + 1, min( dp[i-1][j], dp[i][j-1]) + 1);
	            }
	            //cout<<dp[i][j]<<endl;
	            
	        }
	    }
	    
	    cout<<dp[A.size()][B.size()]<<endl;
	}
	
	return 0;
}
