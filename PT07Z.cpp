#include <bits/stdc++.h>

using namespace std;

int getMaxDepth(vector<int> g[], int depth[], int n, int root) {
	
	bool visited[n+1];
	memset(visited, false, sizeof visited);
	stack<int> s;
	s.push(root);
	depth[root] = 0;
	visited[root] = true;
	while(!s.empty()) {
		int x = s.top();
		s.pop();
		for(int i = 0; i < g[x].size(); ++i) {
			if(visited[g[x][i]])	continue;
			s.push(g[x][i]);
			depth[g[x][i]] = depth[x] + 1;
			visited[g[x][i]] = true;
		}
	}
	return distance(depth, max_element(depth+1, depth + n+1));
}

int main() {

	int n, u, v;
	cin>>n;
	vector<int> g[n+1];
	int depth[n+1];
	for(int i = 0; i < n-1; ++i) {
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	memset(depth, 0, sizeof depth);
	int maxIndex = getMaxDepth(g, depth, n, 1);
	memset(depth, 0, sizeof depth);
	int maxIndex_ = getMaxDepth(g, depth, n, maxIndex);
	cout<<depth[maxIndex_]<<endl;
	return 0;
}
