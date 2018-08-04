#include <bits/stdc++.h>
using namespace std;

int getHash(string hashValue) {
    
    int key = 0;
    for(int i = 0; i < hashValue.size(); ++i) {
        key = (key + (int) hashValue[i] * (i+1));
    }
    return (key * 19) % 101;
}

int getKey(int hash, string value, vector<string> hashTable) {
    
    int index;
    if(hashTable[hash] == value)    return hash;
    for(int j = 0; j  < 20; ++j) {
        index = (hash + j * j + 23 * j);
        if(hashTable[index] == value)   return index;
    }
    return -1;
}

int getOpenAddress(vector<string> hashTable, int index) {
    
    int openIndex;
    if(hashTable[index].empty()) {
        return index;
    }
    for(int j = 1; j < 20; ++j) {
        openIndex = (index + j * j + 23 * j) % 101;
        if(hashTable[openIndex].empty()) {
            return openIndex;
        }
    }
    return openIndex;
}

int main() {
	
	int t, n, openIndex;
	string key, input;
	cin>>t;
	
	while(t--) {
	    
	    vector<string> hashTable(101);
	    cin>>n;
	    while(n--) {
	        
	        cin>>input;
	        string operation = input.substr(0,3), hashValue = input.substr(4);  
	        int hash = getHash(hashValue);
	        int hashKey = getKey(hash, hashValue, hashTable);
	        if(operation[0] == 'A') {
	           if(hashKey == -1) { 
	               openIndex = getOpenAddress(hashTable, hash);
	               if(openIndex >= 0)   hashTable[openIndex] = hashValue;
	            }
	       }
	       else {
	             if(hashKey >= 0) {
	                 hashTable[hashKey].clear();
	             }        
	       }
	        
	    }
	    
	    string output;
	    int counter = 0;
	    for(int i = 0; i < 101; ++i) {
	        //cout<<i<<" "<<hashTable[i]<<endl;
	        if(!hashTable[i].empty()) {
	            ++counter;
	            output += to_string(i) + ":" + hashTable[i] + '\n';
	        }
	    }
	    cout<<counter<<endl<<output;
	    
	}

	return 0;
}
