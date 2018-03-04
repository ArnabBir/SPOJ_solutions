// http://www.spoj.com/problems/FCTRL

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    
    int N;
    
    cin>>N;
    int a[N];
    for(int i = 0; i < N; ++i){
        cin>>a[i];
    }
    
    for(int i = 0; i < N; ++i){
        int power5 = 5;
        int count10 = 0;
        while(power5 <= a[i]){
            count10 += a[i] / power5;
            power5 *= 5;
        }
        cout <<count10<<endl;
    }
    
    return 0;
}
