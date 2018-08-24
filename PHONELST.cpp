#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode * children[10];
    bool isEnd;
};

struct TrieNode * newNode() {
    struct TrieNode * trieNode = new TrieNode;
    for(int i = 0; i < 10; ++i) {
        trieNode->children[i] = NULL;
    }
    trieNode->isEnd = false;
    return trieNode;
}

void insert(struct TrieNode * root, string s) {
    
    struct TrieNode * node = root;
    
    for(int i = 0; i < s.length(); ++i) {
        int index = s[i] - '0';
        if(node->children[index] == NULL) {
            node->children[index] = newNode();
        }
        node = node->children[index];
    }
    node->isEnd = true;
}

bool search(struct TrieNode * root, string s) {
    
    struct TrieNode * node = root;
    
    for(int i = 0; i < s.length(); ++i) {
        int index = s[i] - '0';
        if(node->children[index] == NULL) {
            return false;
        }
        if(node->children[index]->isEnd) {
            return true;
        }
        node = node->children[index];
    }
    return node != NULL;
}

int main() {
    
    int t, n;
    cin>>t;
    
    while(t--) {
        bool consistent = true;
        cin>>n;
        vector<string> s(n);
        struct TrieNode * node = newNode();
        for(int i = 0; i < n; ++i)  cin>>s[i];
        for(int i = 0; i < n; ++i) {
            if(!search(node, s[i])) {
                insert(node, s[i]);
            }
            else {
                consistent = false;
                break;
            }
        }
        if(consistent)  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    
    return 0;
}
