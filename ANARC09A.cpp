#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int count, result;
    int k = 0;
    while(cin>>s) {
        stack<char> st;
        if(s[0] == '-') {
            break;
        }
        count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '{') {
                st.push(s[i]);
            }
            else if(s[i] == '}') {
                if(st.empty()) {
                    ++count;
                    st.push(s[i]);
                }
                else if(st.top() == '{') {
                    st.pop();
                }
                else {
                    ++count;
                    st.push(s[i]);
                }
            }
        }
        if(st.size() == 0) {
            result = 0;
        }
        else {
            result = count/2+((int)st.size()-count)/2+(count%2)*2+(s.size()%2);
        }
        cout<<(++k)<<". "<<result<<endl;
    }
	return 0;
}
