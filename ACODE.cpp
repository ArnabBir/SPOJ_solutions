/* http://www.spoj.com/problems/ACODE/ */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll getAplhaCode(string  n, ll dp[]){

    for(int i = n.size() - 2; i >= 0; --i){
        if(n[i] == '0') dp[i] = 0;
        else if(n[i] < '2')  dp[i] = dp[i+1] + dp[i+2];
        else if(n[i] == '2' && n[i+1] <= '6')   dp[i] = dp[i+1] + dp[i+2];
        else    dp[i] = dp[i+1];
    }
    return dp[0];
}

int main() {
	string n;
	while(true){
	    cin>>n;
	    if(n == "0")    break;
	    ll dp[n.size()+1] = {0};
	    if(n.size() == 0){
	        cout<<0<<endl;
	        continue;
	    }
	    if(n[n.size()-1] != '0')   dp[n.size()-1] = 1;
	    dp[n.size()] = 1;
	    cout<<getAplhaCode(n, dp)<<endl;
	}
	return 0;
}
