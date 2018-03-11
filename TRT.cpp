#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int N, count = 0;
	cin>>N;
	
	long long treat[N+1][N+1] = {0}, maximum = 0;
	int a[N+1];
	
	for(int i = 1; i <= N; ++i){
	    cin>>a[i];
	}
	
    for(int i = 1; i < N; ++i){
        treat[i][i] = a[i] * N;
    }

    for(int i = 0; i <= N; ++i){
        treat[i][0] = treat[0][i] = 0;
    }
    
    for(int i = N-1; i >= 1; --i){
        for(int k = i, j = N; j >= 1, k >= 1; --j, --k){
            int len = N - (j - k);
            treat[k][j] = max(treat[k+1][j] + a[k]*len, treat[k][j-1] + a[j]*len);
        }
    }
	
	cout<<treat[1][N]<<endl;
	
	return 0;
}
