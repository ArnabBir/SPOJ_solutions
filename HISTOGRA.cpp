#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long min_sgtree(long long * h, int l, int r, long long * sgtr, int index){
    
    if(l == r){
        
        sgtr[index] = h[l];
        return sgtr[index];
    }
    
    int mid = l + (r-l)/2;
    
    sgtr[index] = min(min_sgtree(h, l, mid, sgtr, 2 * index + 1), min_sgtree(h, mid+1, r, sgtr, 2 * index + 2));
    return sgtr[index];
}

int get_min_in_range(long long * h, int p, int q, int l, int r, long long * sgtr, int index){
    
    if(p <= l && r <= q)    return index;
    if(p > r || q < l)  return -1;
    
    int mid = l + (r-l) / 2;
    
    int left = get_min_in_range(h, p, q, l, mid, sgtr, 2*index + 1);
    int right = get_min_in_range(h, p, q, mid+1, r, sgtr, 2*index + 2);
    
    if(sgtr[left] < sgtr[right] || right == -1)  return left;
    else return right;
}

long long  get_max_area(long long  * h, int n, int l, int r, long long * sgtr){
    
    if(l+1 == r)  return h[l];
    if(l+1 > r)   return 0;
    
    
    int index = get_min_in_range(h, l, r-1, 0, n-1, sgtr, 0);
    long long  min_h = sgtr[index];    
    
     /*for(int i = l+1; i < r; ++i){
	        
	        if(min_h > h[i]){
	            
	            min_h = h[i];
	            index = i;
	        }
	    }*/
	 
    return max(min_h * (r-l), max(get_max_area(h, n, l, index, sgtr), get_max_area(h, n, index+1, r, sgtr)));
}

int main() {
	
	ios::sync_with_stdio(false);
	
	int n;
	
	while(true){
	    
	    cin>>n;
	    if(n == 0)  break;
	    
	    long long h[n];

	    for(int i = 0; i < n; ++i){
	        
	        cin>>h[i];
	    }
	    long long * sgtr = new long long[2*(int)pow(2, ceil(n))];
	    min_sgtree(h, 0, n-1, sgtr, 0);
	    cout<<get_max_area(h, n, 0, n, sgtr)<<endl;
	}
	
	return 0;
}
