#include <bits/stdc++.h>

using namespace std;

bool sort_by_sec(const pair<int, int> &a, const pair<int, int> &b){

	return a.second < b.second;
}

int main(){

	int T, N, u, v, count, last_t;

	cin>>T;

	while(T--){

		cin>>N;
		vector< pair <int, int> > t(N);

		for(int i = 0; i < N; ++i){

			cin>>u>>v;
			t[i] = make_pair(u, v);
		}

		sort(t.begin(), t.end(), sort_by_sec);

		count = 0;
		last_t = 0;

		for(int i = 0; i < N; ++i){

			if(last_t <= t[i].first){

				++count;
				last_t = t[i].second;
			}
		}

		cout<<count<<endl;

	}

	return 0;
}
