#include <bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

int main() {
	
	int t, n, m;
	ull temp;
	cin>>t;
	while(t--) {
	    priority_queue<ull, vector<ull>, greater<ull>> g, mg;
	    cin>>n>>m;
	    for(int i = 0; i < n; ++i) {
	        cin>>temp;
	        g.push(temp);
	    }
	    for(int i = 0; i < m; ++i) {
	        cin>>temp;
	        mg.push(temp);
	    }
	    while(!g.empty() && !mg.empty()) {
	        if(g.top() < mg.top()) {
	            g.pop();
	        }
	        else {
	            mg.pop();
	        }
	    }
	    if(g.empty())   cout<<"MechaGodzilla"<<endl;
	    else    cout<<"Godzilla"<<endl;
	}
	return 0;
}
