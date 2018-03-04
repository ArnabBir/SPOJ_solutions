#include <bits/stdc++.h>

using namespace std;

long long M[2][2] = {{1,1},{1,0}};

void multiply(long long A[2][2], long long B[2][2]){
    
    long long x1, x2, x3, x4;
    
    x1 = ((A[0][0]*B[0][0] % 1000000007) + (A[0][1]*B[1][0] % 1000000007))%1000000007;
    x2 = ((A[0][0]*B[0][1] % 1000000007) + (A[0][1]*B[1][1] % 1000000007))%1000000007;
    x3 = ((A[1][0]*B[0][0] % 1000000007) + (A[1][1]*B[1][0] % 1000000007))%1000000007;
    x4 = ((A[1][0]*B[0][1] % 1000000007) + (A[1][1]*B[1][1] % 1000000007))%1000000007;
    
    A[0][0] = x1;
    A[0][1] = x2;
    A[1][0] = x3;
    A[1][1] = x4;
}

void power(long long F[2][2], long long n){
    
    if(n == 0 || n == 1)    return;
    
    power(F, n/2);
    multiply(F, F);
    
    if(n%2 != 0)    multiply(F, M);
}

long long getFib(long long n){
    
    if(n == 0)  return 0;
    if(n == 2 || n == 1)    return 1;
    long long F[2][2] = {{1,1},{1,0}};
    
    power(F, n-1);
    
    return F[0][0] % 1000000007;
} 

int main() {
	
	int T;
	long long x, y;
	
	cin>>T;
	
	while(T--){
	    
	    cin>>x>>y;
	    cout<<getFib(y+2) - getFib(x+1)<<endl;
	}
	
	return 0;
}
