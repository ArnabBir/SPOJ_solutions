#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int T, n, x;
    string str;
    cin>>T;
    for(int t = 0; t < T; ++t) {
        cin>>n;
        vector<int> v(n+1, 0);
        stack<int> s;
        cin>>x;
        s.push(x);
        do {
            cin>>x;
            if(s.top() == x) {
                s.pop();
            }
            else {
                ++v[s.top()];
                s.push(x);
            }
        } while(x != 1);
        cout<<"Case "<<t+1<<":"<<endl;
        for(int i = 1; i <= n; ++i) {
            cout<<i<<" -> "<<v[i]<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}
