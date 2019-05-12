#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, m;
	cin>>n>>m;
	vector<string> dict(n), search(m);
	for(int i = 0; i < n; ++i)  cin>>dict[i];
	for(int i = 0; i < m; ++i)  cin>>search[i];
	int index[26][26][26];
	memset(index, 0, sizeof index);
	for(int i = 0; i < n; ++i) {
	    for(int j = 0; j < dict[i].length(); ++j) {
	        for(int k = j+1; k < dict[i].length(); ++k) {
	            for(int l = k+1; l < dict[i].length(); ++l) {
	                if(index[dict[i][j]-'a'][dict[i][k]-'a'][dict[i][l]-'a'] == 0) {
	                    index[dict[i][j]-'a'][dict[i][k]-'a'][dict[i][l]-'a'] = i+1;
	                }
	            }
	        }
	    }
	}
	for(int i = 0; i < m; ++i) {
	    int val = index[search[i][0]-'A'][search[i][1]-'A'][search[i][2]-'A'];
	    if(val == 0) {
	        cout<<"No valid word"<<endl;
	    }
	    else {
	        cout<<dict[val-1]<<endl;
	    }
	}
	return 0;
}
