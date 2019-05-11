#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector< pair<int, int> > * adj, vector<long long int> & dist, int p, int s) {
    
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        
        int u = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < adj[u].size(); ++i) {
            int w = adj[u][i].first;
            int v = adj[u][i].second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
 
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, p, q, a, b, c;
	long long int result;
	cin>>n;
	while(n--) {
	    cin>>p>>q;
	    vector< pair<int, int> > adj[p];
	    vector< pair<int, int> > adjT[p];
	    for(int i = 0; i < q; ++i) {
	        cin>>a>>b>>c;
	        adj[a-1].push_back(make_pair(c, b-1));
	        adjT[b-1].push_back(make_pair(c, a-1));
	    }
	    vector<long long int> dist(p, INT_MAX), dist2(p, INT_MAX);
	    dijkstra(adj, dist, p, 0);
	    dijkstra(adjT, dist2, p, 0);
	    result = accumulate(dist.begin(), dist.end(), 0) + accumulate(dist2.begin(), dist2.end(), 0);
	    cout<<result<<endl;
	}
	return 0;
}
