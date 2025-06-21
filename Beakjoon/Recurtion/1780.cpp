//종이의 개수, 실버 2
//재귀
#include <iostream>
#include <cmath>
using namespace std;
struct State {
    int a, b, c;
};

int board[2188][2188];

State recur(int k, int x, int y) {
    bool flag = true;
    if(k == 0) {
        if(board[x][y] == -1) return {1,0,0};
        if(board[x][y] == 0) return {0,1,0};
        if(board[x][y] == 1) return {0,0,1};
    }
    for(int i = x; i < x+(int)(pow(3,k)); i++) {
        for(int j = y; j < y+(int)(pow(3,k)); j++) {
            if(board[x][y] != board[i][j]) flag =  false;
        }
    }

    State sum = {0,0,0};
    if(flag) {
        if(board[x][y] == -1) sum.a = 1;
        if(board[x][y] == 0) sum.b = 1;
        if(board[x][y] == 1) sum.c = 1;
        return sum;
    }
    int dx = (int)pow(3, k-1);
    State sumArr[9];
    sumArr[0] = recur(k-1, x, y);
    sumArr[1] = recur(k-1, x, y + dx);
    sumArr[2] = recur(k-1, x, y + 2*dx);
    sumArr[3] = recur(k-1, x+dx, y);
    sumArr[4] = recur(k-1, x+dx, y + dx);
    sumArr[5] = recur(k-1, x+dx, y + 2*dx);
    sumArr[6] = recur(k-1, x+2*dx, y);
    sumArr[7] = recur(k-1, x+2*dx, y+dx);
    sumArr[8] = recur(k-1, x+2*dx, y+2*dx);
    
    for(int i = 0; i < 9; i++){
        sum.a += sumArr[i].a;
        sum.b += sumArr[i].b;
        sum.c += sumArr[i].c;
    }

    return sum;
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
    int k = 0;
    for(int i = 1; i <= 7; i++) {
        if((int)pow(3,i) == n){
            k = i;
            break;
        }
    }
    State ans = recur(k, 0,0);
    cout << ans.a << '\n';
    cout << ans.b << '\n';
    cout << ans.c << '\n';
    return 0;
}