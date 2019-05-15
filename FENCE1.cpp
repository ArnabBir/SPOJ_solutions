#include <bits/stdc++.h>
#define PI 3.1415926

using namespace std;

int main() {
	
	int L;
	while(true) {
	    cin>>L;
	    if(L == 0)  break;
	    printf("%0.2f\n", ((L * L) / (2.0*PI)));
	}
	return 0;
}
