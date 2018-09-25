#include <bits/stdc++.h>
using namespace std;

int dx[2] = {0, 1};
int dy[2] = {1, 0};
bool domino[7][7] = {false};
bool visited[7][8] = {false};
int box[7][8];
int result;

void countCombos(int x, int y) {
    
    //cout<<x<<" "<<y<<endl;
    
    if(x==7) {
        ++result;
        return;
    }
    
    if(!visited[x][y]) {
        int val = box[x][y];
        for(int d = 0; d < 2; ++d) {
            int xNew = x + dx[d];
            int yNew = y + dy[d];
            if(xNew >= 0 && xNew < 7 && yNew >= 0 && yNew < 8 && !visited[xNew][yNew]) {
            int valNew = box[xNew][yNew];
            // if(val > valNew) {
            //     swap(val, valNew);
            // }
            // if(domino[val][valNew]) {
            //    visited[x][y] = true;
            //    domino[val][valNew] = false;
            //    visited[xNew][yNew] = true;
            //    if(y < 7) {
            //        countCombos(x, y+1);
            //    }
            //    else {
            //        countCombos(x+1, 0);
            //    }
            //    visited[x][y] = false;
            //    domino[val][valNew] = true;
            //    visited[xNew][yNew] = false;
            // }
            if(val <= valNew && domino[val][valNew]) {
                visited[x][y] = true;
                domino[val][valNew] = false;
                visited[xNew][yNew] = true;
                if(y < 7) {
                   countCombos(x, y+1);
                }
                else {
                   countCombos(x+1, 0);
                }
                visited[x][y] = false;
                domino[val][valNew] = true;
                visited[xNew][yNew] = false;
            }
            else if(domino[valNew][val]) {
                visited[x][y] = true;
                domino[valNew][val] = false;
                visited[xNew][yNew] = true;
                if(y < 7) {
                   countCombos(x, y+1);
                }
                else {
                   countCombos(x+1, 0);
                }
                visited[x][y] = false;
                domino[valNew][val] = true;
                visited[xNew][yNew] = false;
            }
        }
    }
  }
  else {
      if(y < 7) {
          countCombos(x, y+1);
      }
      else {
          countCombos(x+1, 0);
      }
  }
}

int main() {
      
    int t;
    cin>>t;
    
    for(int i = 0; i < 7; ++i) {
        for(int j = i; j < 7; ++j) {
            domino[i][j] = true;
        }
    }
    
    while(t--) {
        result = 0;
        for(int i = 0; i < 7; ++i) {
            for(int j = 0; j < 8; ++j) {
                cin>>box[i][j];
            }
        }
        
        countCombos(0, 0);
        cout<<result<<endl;
    }
  return 0;
}
