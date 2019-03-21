#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	long long int n, sq, remainder;
	cin>>t;
	while(t--){
		cin>>n;
		double nRootDouble = sqrt(n), rRootDoube;
		long long int nRoot = (long long int) sqrt(n), rRoot;
		if(nRoot == nRootDouble) {
		    cout<<"Yes"<<endl;
		}
		else {
		    bool flag = false;
		    for(long long int i = 1; i < sqrt(n); ++i) {
		        sq = i * i;
		        remainder = n - sq;
		        rRootDoube = sqrt(remainder);
		        rRoot = (long long int) sqrt(remainder);
		        if(rRoot == rRootDoube) {
		            flag = true;
		            break;
		        }
		    }
		    if(flag) {
		        cout<<"Yes"<<endl;
		    }
		    else {
		        cout<<"No"<<endl;
		    }
		}
	}
}
