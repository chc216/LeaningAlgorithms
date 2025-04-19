#include <iostream>
#include <utility>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;

char board[101][101];
int dis[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i++){
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= m; j++){
            dis[i][j] = -1;
            board[i][j] = tmp.at(j-1);
        } 
    }

 
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    // cout << "board 1, 2: " << board[1][2] <<'\n';
    // cout << "board 1, 1: " << board[1][1] <<'\n';
    queue<pair<int, int>> Q;
    Q.push({1,1}); 
    dis[1][1] = 1;
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(board[nx][ny] == '0' || dis[nx][ny] != -1) continue;
            Q.push({nx,ny});
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << dis[n][m];
    return 0;
}