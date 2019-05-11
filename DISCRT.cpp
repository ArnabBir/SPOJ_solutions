#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, k, a, count = 0;
    cin>>n>>k>>a;
    long x = a;
    vector<int> v;
    while(x < n) {
        ++count;
        v.push_back(x);
        x *= a;
    }
    cout<<count<<endl;
    for(int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
    
    return 0;
}
