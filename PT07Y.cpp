#include <bits/stdc++.h>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int N, M, v1, v2, p;

	cin>>N>>M;

	if(N-1 != M){

		cout<<"NO"<<endl;
	}
	else{
	
		vector<int> v[N+1];	
		bool visited[N+1] = {false};
		int depth[N+1] = {0};
		int v_count;
		for(int i = 0; i < M; ++i){

			cin>>v1>>v2;
			v[v1].push_back(v2);
			v[v2].push_back(v1);
		}

		bool flag = false;

		stack<int> s;

		s.push(1);
		visited[1] = true;
		depth[p] = 1;
		v_count = 1;

		while(!s.empty()){
			
			p = s.top();
			s.pop();

			for(int i = 0; i < v[p].size(); ++i){

				if(!visited[v[p][i]]){

					s.push(v[p][i]);
					visited[v[p][i]] = true;
					depth[v[p][i]] = depth[p] + 1;
					++v_count;
				}
				else if(depth[v[p][i]] != depth[p] - 1){
					flag = true;
				}
			}
		}

		if(!flag && v_count == N)	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	
	return 0;

}
