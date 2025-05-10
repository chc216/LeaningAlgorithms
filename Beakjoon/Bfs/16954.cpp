#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
struct Point {int x, y, t;};
int dx[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int dy[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

char board[8][8][9];
bool vis[8][8][9];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> board[i][j][0];
        }
    }
    for(int t = 0; t < 8; t++){
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 8; j++){
                board[i+1][j][t+1] = board[i][j][t];
            }
        }
    }
    for(int t = 1; t < 9; t++){
        for(int j = 0; j < 8; j++){
            board[0][j][t] = '.';
        }
    }

    queue<Point> Q;
    Q.push({7, 0, 0});
    vis[7][0][0] = 1;
    
    while(!Q.empty()){
        Point cur = Q.front(); Q.pop();
        // cout << '\n' << cur.x << " " << cur.y;
        if(cur.x == 0 && cur.y == 7){
            cout << 1;
            return 0;
        }
        for(int dir = 0; dir < 9; dir++){
        
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nt = min(8, cur.t + 1);
            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            if(board[nx][ny][nt] == '#' || board[nx][ny][cur.t] == '#') continue;
            if(vis[nx][ny][nt]) continue;
            Q.push({nx,ny,nt});
            vis[nx][ny][nt] = 1;
        }
    }
    cout << 0;
    return 0;
}

