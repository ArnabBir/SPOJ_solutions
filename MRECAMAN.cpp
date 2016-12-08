#include <iostream>
#include<algorithm>

using namespace std;

int dp[500000];
bool isPresent[10000000] = {0}; 

int Recaman(int m){
	int result;
	for(int i = 1; i < m; ++i){
		result = dp[i-1] - i;
		if(result > 0 && !isPresent[result]){
			dp[i] = result;
			isPresent[result] = 1;	
		}
		else{
			dp[i] = dp[i-1] + i;
			isPresent[dp[i]] = 1;
		}
	}
}

int main() {
	int k[500000];
	dp[0] = 0;
	dp[1] = 1;
	int itr = 0;
	while(true){
		cin>>k[itr];
		if(k[itr] == -1) break;
		++itr;
	}

	Recaman(*max_element(k, k + itr) + 1);
	for(int i = 0; i < itr; ++i){
		cout<<dp[k[i]]<<endl;
	}

	return 0;
}
