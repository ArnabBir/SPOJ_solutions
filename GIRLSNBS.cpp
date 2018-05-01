#include <bits/stdc++.h>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int G, B, h, l;

	while(true){

		cin>>G>>B;
		if(G == -1 && B == -1)	break;
		h = G > B ? G : B;
		l = G < B ? G : B;
		
		if(h == 0){
			
			cout<<0<<endl;
		}
		else if(l == 0){

			cout<<h<<endl;
		}
		else	if(h == l){
			
			cout<<1<<endl;
		}
		else{

			cout<<( h / (l+1) + ((h % (l+1)) > 0) )<<endl;
		}

	}

	return 0;
}
