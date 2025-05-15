//벽 부수고 이동하기 2, 골드 3
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char board[1001][1001];
int dis[1001][1001][11];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

struct State {
    int x, y, k;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }
    queue<State> Q;
    Q.push({1,1,k});
    dis[1][1][k] = 1;
    while(!Q.empty()){
        State cur = Q.front(); Q.pop();
        // if(cur.x == n && cur.y == m) break;

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(board[nx][ny] == '1' && cur.k > 0){  
                int k = cur.k - 1;
                if(dis[nx][ny][k]) continue;
                Q.push({nx,ny,k});
                dis[nx][ny][k] = dis[cur.x][cur.y][cur.k] + 1;
            }
            else if(board[nx][ny] == '0'){
                int k = cur.k;
                if(dis[nx][ny][k]) continue;
                Q.push({nx,ny,k});
                dis[nx][ny][k] = dis[cur.x][cur.y][cur.k] + 1;
            }
        }
    }

    int ans = 0x7fffffff;
    bool flag = false;
    for(int i = 0; i <= k; i++){
        if(dis[n][m][i] > 0){
            flag = true;
            ans = min(dis[n][m][i], ans);
        }
    }

    if(flag){
        cout << ans;
        return 0;
    }
    cout << -1;
    return 0;
}