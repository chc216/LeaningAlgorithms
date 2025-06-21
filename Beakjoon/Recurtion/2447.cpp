#include <iostream>
#include <cmath>
using namespace std;

char board[6561][6561];

void recur(int k, int x, int y) {
    if(k == 1) {
        int cnt = 0;
        for(int i = x; i < x + 3; i++) {
            for(int j = y; j < y + 3; j++) {
                if(cnt == 4) {
                    board[i][j] = ' ';
                    cnt++;
                    continue;
                }
                cnt++;
                board[i][j] = '*';
            }
        }
        return;
    }
    int d = (int)pow(3,k-1);
    recur(k-1, x, y);
    recur(k-1, x, y+d);
    recur(k-1, x, y+2*d);
    recur(k-1, x+d, y);
    for(int i = x+d; i < x+d+d; i++) {
        for(int j = y+d; j < y+d+d; j++) {
            board[i][j] = ' ';
        }
    }
    recur(k-1, x+d, y+2*d);
    recur(k-1, x+2*d, y);
    recur(k-1, x+2*d, y+d);
    recur(k-1, x+2*d, y+2*d);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    int k = 0;
    for(int i = 1; i <= 8; i++) {
        if((int)pow(3,i) == n) k = i;
    }
    recur(k, 0,0);

    for(int i = 0; i < n; i++) {    
        for(int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}