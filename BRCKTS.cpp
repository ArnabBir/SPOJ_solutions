#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t = 1, n, m, count, q;
	string str;
	bool swapped, balanced;
	
	while(t--) {
	    //swapped = true;
	    balanced = true;
	    cin>>n;
	    cin>>str;
	    cin>>m;
	    int dp[n];
	    for(int i = 0; i < n; ++i) {
	        if(i == 0) {
	            dp[i] = (str[i] == '(') ? 1 : -1;
	        }
	        else {
	            dp[i] = dp[i-1] + (str[i] == '(') ? 1 : -1; 
	        }
	        cout<<dp[i]<<endl;
	        if(dp[i] < 0)   balanced = false;
	        
	    }
	    cout<<dp[n-1]<<endl;
	    if(dp[n-1] != 0)    balanced = false;
	    else    balanced = true;

	    while(m--) {
            cin>>q;
	        if(q != 0) {
	            str[q-1] = (str[q-1] == '(') ? ')' : '(';
	            int delta = (str[q-1] == '(') ? -2 : 2;
	            for(int i = q - 1; i < n; ++i) {
	                dp[i] += delta;
	                if(dp[i] < 0)   balanced = false;
	            }
	            if(dp[n-1] != 0)    balanced = false;
	            else    balanced = true;
	            //swapped = true;
	        }
	        else { 
	           // if(swapped){
	           //     count = 0;
	           //     for(int i = 0; i < n; ++i) {
	           //         count += (str[i] == '(') ? 1 : -1;
	           //         if(count < 0) {
	           //             break;
	           //         }
	           //     }
	           //     if(count == 0) {
	           //         balanced = true;
	           //     }
	           //     else {
	           //         balanced = false;
	           //     }
	           // }
	           // swapped = false;
	            cout<< (balanced ? "YES" : "NO") <<endl; 
	        }
	    }
	}

	return 0;
}
