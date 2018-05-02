#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int n, count;
	vector<int>::iterator lower_lhs, lower_rhs, upper_lhs, upper_rhs;
	cin>>n;

	int s[n];

	//unordered_map<int, int> lhs, rhs;
	vector<int> lhs, rhs;

	for(int i = 0; i < n; ++i){

		cin>>s[i];
	}

	for(int i = 0; i < n; ++i){

		for(int j = 0; j < n; ++j){

			for(int k = 0; k < n; ++k){

				//++lhs[s[i] * s[j] + s[k]];
				lhs.push_back(s[i] * s[j] + s[k]);
			}
		}
	}

	for(int i = 0; i < n; ++i){

		for(int j = 0; j < n; ++j){

			for(int k = 0; k < n; ++k){

				if(s[k] != 0)	/*++rhs[s[i] + s[j]) * s[k]];*/		rhs.push_back((s[i] + s[j]) * s[k]);
			}
		}
	}

	//sort(lhs.begin(), lhs.end());
	sort(rhs.begin(), rhs.end());
	
	count = 0;

/*	for(auto it1 : lhs){

		for(auto it2 : rhs){

			if(it1->first == it2->first){

				count += it1->second * it2->second;
			}
		}
	}*/


	for(int i = 0; i < lhs.size(); ++i){


		//lower_lhs = lower_bound(lhs.begin(), lhs.end(), lhs[i]);
		lower_rhs = lower_bound(rhs.begin(), rhs.end(), lhs[i]);
		//upper_lhs = upper_bound(lhs.begin(), lhs.end(), lhs[i]);
		upper_rhs = upper_bound(rhs.begin(), rhs.end(), lhs[i]);

		count += (upper_rhs - lower_rhs);
		
	}

	cout<<count<<endl;

	return 0;
}
