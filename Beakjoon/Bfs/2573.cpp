#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int board[300][300];
int tmp_board[300][300];
int vis[300][300];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    int t = 0;
    while(1){
        int area = 0;
        queue<pair<int, int>> Q;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] > 0 && vis[i][j] == 0){
                    // cout << vis[i][j];
                    // cout << "t : " << t << '\n';
                    Q.push({i,j});
                    vis[i][j] = 1;
                    area++;
                    while(!Q.empty()){
                        pair<int, int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                            Q.push({nx,ny});
                            vis[nx][ny] = 1;     
                        }
                    }
                }
            }
        }
        // cout << "hey!";
        if(area >= 2){
            cout << t;
            return 0;
        }
        if(area == 0){
            cout << 0;
            return 0;
        }
        t++;
        memset(tmp_board, 0, sizeof(tmp_board));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0) continue;
                int cnt = 0;
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] == 0){
                        cnt++;
                    }
                }
                tmp_board[i][j] = max(0, board[i][j] - cnt);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = tmp_board[i][j];
            }
        }
    }
}