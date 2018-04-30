#include <bits/stdc++.h>

using namespace std;

long long construct_sgtr(int * a, int l, int h, int p, int q, long long * sgtr, int c){

	if(l == h){
	
		sgtr[c] = a[l];
		return sgtr[c];
	}

	int mid = l + (h-l)/2;

	sgtr[c] = construct_sgtr(a, l, mid, p, q, sgtr, 2*c) + construct_sgtr(a, mid+1, h, p, q, sgtr, 2*c + 1);
	
	return sgtr[c];
}

long long get_sum(long long * sgtr, int l, int h, int p, int q, int c){

	if(p <= l && h <= q)	return sgtr[c];

	if(h < p || l > q)	return 0;

	int mid = l + (h-l)/2;

	return get_sum(sgtr, l, mid, p, q, 2*c) + get_sum(sgtr, mid+1, h, p, q, 2*c+1);
}

int main(){

	ios::sync_with_stdio(false);		
	
	int T, N, C, x, p, q, v;

	cin>>T;

	while(T--){

		cin>>N>>C;

		int a[N+1] = {0};
		long long * sgtr;

		while(C--){

			cin>>x>>p>>q;

			if(x == 0){

				cin>>v;
				//cout<<x<<" "<<v<<endl;
				int treesize = 2*(int)pow(2, (int)(ceil(log2(N))));
				sgtr = new long long[treesize+1];

				for(int i = p; i <= q; ++i){

					a[i] += v;
					//cout<<a[i]<<endl;
				}

				construct_sgtr(a, 1, N, p, q, sgtr, 1);
				//for(int i = 1; i <= treesize; ++i)	cout<<sgtr[i]<<endl;
			}
			else if(x == 1){

				cout<<get_sum(sgtr, 1, N, p, q, 1)<<endl;
			}
		}

	}

	return 0;
}
