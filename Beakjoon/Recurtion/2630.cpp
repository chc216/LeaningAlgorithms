#include <iostream>
#include <utility>
using namespace std;

bool board[129][129];

pair<int,int> recur(int n, int x, int y) {
    if(n == 1) {
        if(board[x][y] == 0){
            return {1,0};
        }
        if(board[x][y] == 0){
            return {0,1};
        }
    }
    int pivot = board[x][y];
    bool flag = true;
    for(int i = x; i < x+n; i++) {
        for(int j = y; j < y+n; j++) {
            if(board[i][j] != pivot) flag = false;
        }
    }
    if(flag) {
        pair<int, int> sum;
        if(pivot == 0) {
            sum.first = 1;
            sum.second = 0;
            return sum;
        }
        if(pivot == 1) {
            sum.first = 0;
            sum.second = 1;
            return sum;
        }
    }

    pair<int,int> sum[4];
    sum[0] = recur(n/2, x,y);    
    sum[1] = recur(n/2, x, y + n/2);
    sum[2] = recur(n/2, x + n/2, y);
    sum[3] = recur(n/2, x + n/2, y + n/2);

    pair<int, int> ans = {0,0};
    for(pair<int, int> a : sum) {
        ans.first += a.first;
        ans.second += a.second;
    }
    return ans;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    recur(8, 0, 0);
    return 0;
}