#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t = 1, n, m, count, q;
	string str;
	bool swapped, balanced;
	int closed;
	
	while(t--) {
	    
	    balanced = true;
	    closed = -1;
	    cin>>n;
	    cin>>str;
	    cin>>m;
	    int dp[n];
	    
	    for(int i = 0; i < n; ++i) {
	        if(i == 0) {
	            dp[i] = (str[i] == '(') ? 1 : -1;
	        }
	        else {
	            dp[i] = dp[i-1] + ((str[i] == '(') ? 1 : -1); 
	        }
	        if(dp[i] < 0)   closed = i;
	    }
	    
	    if(dp[n-1] != 0)    balanced = false;
	    else    balanced = true;

	    while(m--) {
            cin>>q;
	        if(q != 0) {
	            //closed = balanced;
	            if(closed >= q-1 )    closed = -1;
	            str[q-1] = (str[q-1] == '(') ? ')' : '(';
	            int delta = (str[q-1] == '(') ? 2 : -2;
	            for(int i = q - 1; i < n; ++i) {
	                dp[i] += delta;
	                if(dp[i] < 0)   closed = min(closed, i);
	            }
	            if(dp[n-1] != 0)    balanced = false;
	            else    balanced = true;
	        }
	        else { 
	            cout<< (balanced & (closed == -1) ? "YES" : "NO") <<endl; 
	        }
	    }
	}

	return 0;
}
