#include <bits/stdc++.h>

using namespace std;

int main(){

	int t, x, n;

	cin>>t;

	while(t--){

		cin>>x;

		n = 2;

		while(x > (n * (n-1)) / 2)	++n;

		if(n%2)	cout<<"TERM "<<x<<" IS "<<(x - ((n-1) * (n-2))/2)<<"/"<<(((n) * (n-1))/2 - x + 1)<<endl;
		else	cout<<"TERM "<<x<<" IS "<<(((n) * (n-1))/2 - x + 1)<<"/"<<(x - ((n-1) * (n-2))/2)<<endl;
	}

	return 0;
}
