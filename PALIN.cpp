#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	string s;
	cin>>n;
	while(n--) {
	    cin>>s;
	    int l = s.length();
	    int del = 0;
	    bool swapped = false, all9 = false;
	    for(int i = 0; i < l/2; ++i) {
	       if(s[l/2-1-i] < s[l/2+(l%2)+i]) {
	          del = l/2-1-i;
	          break;
	       }
	       else if(s[l/2-1-i] > s[l/2+(l%2)+i]){
	           swapped = true;
	           break;
	       }
	    }
	   if(!swapped) {
	        all9 = true;
	        for(int i = l/2 + (l%2)-1; i >= del; --i) {
	            if(s[i] == '9') {
	                s[i] = '0';
	            }
	            else {
	                all9 = false;
	                s[i] += 1;
	                break;
	            }
	        }
	   }
	   if(all9) {
	       s = '1' + s;
	       l += 1;
	   }
	   for(int i = 0; i < l/2; ++i) {
	       s[l/2 +(l%2)+i] = s[l/2-1-i];
	   }
	    cout<<s<<endl;
	}
	return 0;
}
