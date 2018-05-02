#include <bits/stdc++.h>

#define WHITE 0
#define RED 1
#define BLUE 2

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int T, n, m, u, v, p;
	bool flag;

	cin>>T;

	for(int t = 1; t <= T; ++t){

		cin>>n>>m;

		vector<int> g[n+1];
		int color[n+1] = {WHITE};
		bool visited[n+1] = {false};
		flag = false;

		for(int i = 0; i < m; ++i){

			cin>>u>>v;

			g[u].push_back(v);
			g[v].push_back(u);
		}

		queue<int> q;

		for(int s = 1; s <= n; ++s){
			
			if(!visited[s]){

				q.push(s);
				visited[s] = true;
				color[s] = RED;

				while(!q.empty()){

					p = q.front();
					q.pop();

					for(int i = 0; i < g[p].size(); ++i){

						if(!visited[g[p][i]]){

							visited[g[p][i]] = true;
							q.push(g[p][i]);

							if(color[g[p][i]] == WHITE){

								if(color[p] == RED)	color[g[p][i]] = BLUE;
								else color[g[p][i]] = RED;
							}
							// else{

							// 	if(color[p] == color[g[p][i]]){

							// 		flag = true;
							// 		break;
							// 	}
							// }
						}
						else{

							if(color[p] == color[g[p][i]]){

									flag = true;
									break;
							}
						}
					}
				}
			}
		}
		cout<<"Scenario #"<<t<<":"<<endl;
		if(flag)	cout<<"Suspicious bugs found!"<<endl;
		else	cout<<"No suspicious bugs found!"<<endl;
	}

	return 0;
}
