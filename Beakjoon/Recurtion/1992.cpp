#include <iostream>
using namespace std;

bool board[65][65];

void recur(int n, int x, int y) {
    if(n == 1) {
        cout << board[x][y];
        return;
    }
    bool flag = true;
    for(int i = x; i < x +n; i++) {
        for(int j = y; j < y + n; j++) {
            if(board[x][y] != board[i][j]) flag = false;
        }
    }
    if(flag) {
        cout << board[x][y];
        return;
    }
    cout << '(';
    recur(n/2, x, y);
    recur(n/2, x, y + n/2);
    recur(n/2, x + n/2, y);
    recur(n/2, x + n/2, y + n/2);
    cout << ')';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < n; j++) {
            board[i][j] = (int)(tmp[j] - '0');
        }
    }
    recur(n, 0, 0);
    return 0;
}