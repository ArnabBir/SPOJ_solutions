#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// vector< vector<int> > adj = {
//     {1, 2, 4, 5, 6, 7, 9},
//     {1, 3, 4, 5, 6, 8, 9},
//     {2, 3, 4, 5, 7, 8, 9},
//     {1, 2, 3, 4, 6, 7, 8, 9},
//     {1, 2, 3, 5, 6, 7, 8, 9},
//     {1, 2, 4, 5, 6, 7, 8, 9},
//     {1, 3, 4, 5, 6, 7, 8},
//     {2, 3, 4, 5, 6, 7, 9},
//     {1, 2, 3, 4, 5, 6, 8, 9}
// };

// unsigned long long int bigPower(unsigned long long int x, unsigned long long int n) {
    
//     if(n == 0)  return 1;
//     if(n == 1)  return x;
//     unsigned long long int a = bigPower(x, n/2);
//     if(n%2) return ((a * a) * x);
//     else    return (a * a);
// }

// unsigned long long int bigPower(unsigned long long int x, unsigned long long int y)  { 

//     unsigned long long int res = 1;      
//     x = x % MOD;
//     while (y > 0) { 
//         if (y & 1) 
//             res = (res*x) % MOD; 
//         y = y>>1;
//         x = (x*x) % MOD;   
//     } 
//     return res; 
// } 

unsigned long long int exponentMod(unsigned long long int A, unsigned long long int B) {
    
    if (A == 0) return 0; 
    if (B == 0) return 1; 
    unsigned long long int y;
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2); 
        y = (y * y) % MOD; 
    }
    else { 
        y = A % MOD; 
        y = (y * exponentMod(A, B - 1) % MOD) % MOD; 
    } 
    return (unsigned long long int)((y + MOD) % MOD); 
} 

int main() {
	
	int t;
	unsigned long long int n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    if(n == 1)  cout<<6<<endl;
	    else    cout<<((5 * exponentMod(7, n-1))%MOD + (4 * exponentMod(8, n-1))%MOD)%MOD<<endl;
	}
	return 0;
}
