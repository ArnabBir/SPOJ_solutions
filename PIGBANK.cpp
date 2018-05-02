#include <bits/stdc++.h>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int T, E, F, n, m, u, v;

	cin>>T;

	while(T--){

		cin>>E>>F>>n;
		m = F - E;
		int w[n], p[n], c[m+1];

		memset(c, -1, sizeof(c));

		for(int i = 0; i < n; ++i){

			cin>>u>>v;
			p[i] = u;
			w[i] = v;
		}

		c[0] = 0;

		for(int i = 0; i < n; ++i){

			for(int j = 0; j <= m; ++j){

				if(j + w[i] <= m && c[j] != -1){

					if(c[j + w[i]] > c[j] + p[i] || c[j + w[i]] == -1){

						c[j + w[i]] = c[j] + p[i];
					}
				}
			}
		}

		if(c[m] == -1)	cout<<"This is impossible."<<endl;
		else	cout<<"The minimum amount of money in the piggy-bank is "<< c[m] <<"."<<endl;
		
	}

	return 0;
}
