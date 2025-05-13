#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int board[201][201];
int dis[201][201][31];

int dx[12] = {-1, -2, -2, -1, 1, 2, 2, 1, 0, -1, 0, 1};
int dy[12] = {2, 1, -1, -2, -2, -1, 1, 2, 1, 0, -1, 0};

struct State {
    int x,y,n;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, h, w;
    cin >> k >> w >> h;    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> board[i][j];
        }
    }
    queue<State> Q;
    Q.push({0,0,k});
    dis[0][0][k] = 1;
    while(!Q.empty()){
        State cur = Q.front(); Q.pop();
        if(cur.x == h-1 && cur.y == w-1) break;
        // 말 이동
        if (cur.n > 0) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                int n = cur.n - 1;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == 1 || dis[nx][ny][n] > 0) continue;
                dis[nx][ny][n] = dis[cur.x][cur.y][cur.n] + 1;
                Q.push({nx, ny, n});
            }
        }
// 일반 이동
        for (int dir = 8; dir < 12; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int n = cur.n;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == 1 || dis[nx][ny][n] > 0) continue;
            dis[nx][ny][n] = dis[cur.x][cur.y][cur.n] + 1;
            Q.push({nx, ny, n});
        }
    }
    // cout << sizeof(int);

    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    int ans = 0x7fffffff;
    bool flag = false;
    for(int i = 0; i <= k; i++) {
        if(dis[h-1][w-1][i] == 0) continue;
        flag = true;
        ans = min(ans, dis[h-1][w-1][i] - 1);
    }
    if(!flag) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}