#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int board[101][101];
int dis[101][101][2];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

struct State {
    int x, y;
    bool hasItem;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }
    queue<State> Q;
    if(board[1][1] == 0){
        Q.push({1,1,0});
        dis[1][1][0] = 1;
    }
    else if(board[1][1] == 2){
        Q.push({1,1,1});
        dis[1][1][1] = 1;
    }
    
    while(!Q.empty()){
        State cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(cur.hasItem){
                if(dis[nx][ny][1]) continue;
                Q.push({nx,ny,1});
                dis[nx][ny][1] = dis[cur.x][cur.y][1] + 1;
            }
            else {
                if(board[nx][ny] == 1) continue;
                if(board[nx][ny] == 2){
                    if(dis[nx][ny][1]) continue;
                    Q.push({nx,ny,1});
                    dis[nx][ny][1] = dis[cur.x][cur.y][0] + 1;
                    continue;
                }
                if(board[nx][ny] == 0){
                    if(dis[nx][ny][0]) continue;
                    Q.push({nx,ny,0});
                    dis[nx][ny][0] = dis[cur.x][cur.y][0] + 1;

                }
                
            }
        }
    }

    bool flag = false;
    int ans = 0x7fffffff;
    for(int i = 0; i < 2; i++){
        if(dis[n][m][i] > 0){
            flag = true;
            ans = min(ans, dis[n][m][i] - 1);
        }
    }

    if(flag && ans <= t){
        cout << ans;
        return 0;
    }
    cout << "Fail";
    return 0;

    
}