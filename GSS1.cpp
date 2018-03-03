#include <bits/stdc++.h>
using namespace std;

int segTree[2*15007] = {0};

int buildST(int * arr, int start, int end, int current){
    
    if(start == end){
        segTree[current] = arr[start];
        return segTree[current];
    }
    
    int mid = (start + end) >> 1;
    segTree[current] = buildST(arr, start, mid, 2*current+1)
                + buildST(arr, mid+1, end, 2*current+2);
                
    return segTree[current];
}

//int mergeST()

int Query(int index, int start, int end, int x, int y){
    
    if(start == x && end == y)  return segTree[index];
    
    int left = index<<1;
    int right = (index<<1)+1;
    int mid = (start + end) >> 1;
    
    if(y <= mid)    return Query(left, start, mid, x, y);
    if(x > mid)     return Query(right, mid+1, end, x, y);
    
    return Query(left, start, mid, x, mid) + Query(left, mid+1, end, mid+1, y);
    
    
}

int main() {
	
	int N, M, x, y;
	
	cin>>N;
	int a[N];
	
	for(int i = 0; i < N; ++i){
	    cin>>a[i];
	}
	
	buildST(a, 0, N-1, 0);
	
	cin>>M;
	
	while(M--){
	    cin>>x>>y;
	    cout<<Query(0, 0, N-1, x-1, y-1)<<endl;
	}
	
	return 0;
}
