#include <iostream>
using namespace std;

int main() {
	
	int a, b, c;
	
	while(true) {
	    cin>>a>>b>>c;
	    if(!(a | b | c))    break;
	    if(b - a == c - b)  cout<<"AP "<<c+b-a<<endl;
	    else if(a * c == b * b) cout<<"GP "<<c*c/b<<endl;
	}

	return 0;
}
