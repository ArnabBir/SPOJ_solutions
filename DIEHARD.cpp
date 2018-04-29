#include <bits/stdc++.h>

using namespace std;

int main(){

	int T, A, H, count;

	cin>>T;

	while(T--){

		cin>>H>>A;

		count = -1;
		
		while(A > 0 && H > 0){
			
			count += 2;

			H += 3;
			A += 2;

			if( H > 20 && A <= 10){

				H -= 20;
				A += 5;
			}
			else if(H > 5 && A > 10){

				H -= 5;
				A -= 10;	
			}
			else{
				break;
			}
		}

		cout<<count<<endl;
	}

	return 0;
}
