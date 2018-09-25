#include <bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin>>t;
	string exp;

	while(t--) {
		stack<char> s;
		int count = 0;
		cin>>exp;
		for(int i = 0; i < exp.length(); ++i) {
			if(exp[i] == '(') {
				++count;
			}
			else if(exp[i] >= 'a' && exp[i] <= 'z') {
				cout<<exp[i];
			}
			else if(exp[i] == ')') {
				cout<<s.top();
				s.pop();
			}
			else {
				s.push(exp[i]);
			}
		}
		cout<<endl;
	}

	return 0;
}
