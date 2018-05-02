#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, a, b, x;
	cin>>t;
	while(t--){
		cin>>a>>b;
		
		if(a == 0)	x = 0;
		else if(b == 0)	x = 1;
		else{
			a %= 10;
			b %= 4;
			if(b == 0)	x = (a*a*a*a) % 10;
			else if(b == 1)	x = (a) % 10;
			else if(b == 2)	x = (a*a) % 10;
			else	x = (a*a*a) % 10;
		}
		cout<<x<<endl;
	}
}
