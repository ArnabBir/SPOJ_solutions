#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, index;
    string code;
    while(true) {
        cin>>n;
        if(n == 0)  break;
        index = 0;
        cin>>code;
        int m = code.size()/n;
        for(int j = 0; j < n; ++j) {
            for(int i = 0; i < m; ++i) {
                if(i % 2 == 0) {
                    cout<<code[n*i + j];
                }
                else {
                    cout<<code[(i+1)*n - 1 - j];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
