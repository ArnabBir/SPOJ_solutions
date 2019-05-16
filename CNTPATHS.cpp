#include <bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

int main() {
	
	int T, n, t, s, x;
	ull dist, count;
	char temp;
	string inp;
	cin>>T;
	x = 0;
	while(x++ < T) {
	    cin>>n>>t;
	    vector<vector<int> > adj(n, vector<int>(n, INT_MAX));
	    for(int i = 0; i < n; ++i) {
	        cin>>inp;
	        for(int j = 0; j < n; ++j) {
	            if(inp[j] != '-') {
	                adj[i][j] = inp[j]-'0';
	            }
	        }
	    }
	    s = 0;
	    dist = 0;
	    count = 0;
	    stack<pair<bool, pair<int, ull> > > st;
	    st.push(make_pair(false, make_pair(s, 0)));
	    while(!st.empty()) {
	        pair<bool, pair<int, ull> > p = st.top();
	        st.pop();
	        bool visited1 = p.first;
	        dist = p.second.second;
	        s = p.second.first;
	        for(int i = 0; i < adj[s].size(); ++i) {
	            if(adj[s][i] < INT_MAX) {
	                if(dist + adj[s][i] <= t) {
	                    if(i == 0 && s) {
	                        count += t / dist - 1; 
	                    }
	                    else {
	                        if(i == 1) ++count;
	                        st.push(make_pair(s, make_pair(i, dist + adj[s][i])));
	                    }
	                }
	            }
	        } 
	    }
	    cout<<"Case #"<<x<<": "<<count<<endl;
	}
	return 0;
}
