//7576 토마토
//골드 5, bfs, 멀티소스bfs
#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second
using namespace std;

const int MAX = 1001;
int board[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
    int n, m;
    cin >> m >> n;
    bool hasZero = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) hasZero = true;
            dist[i][j] = -1;
        }
    }
    if(hasZero == false){
        cout << 0;
        return 0;
    }

    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1 && dist[i][j] == -1){
                Q.push({i, j}); dist[i][j] = 0;
            }
        }
    }
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 1 || board[nx][ny] == -1 || dist[nx][ny] != -1) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    // cout << "----------\n" <<'\n';
    int maxDay = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 && dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            if(dist[i][j] > maxDay){
                maxDay = dist[i][j];
            }
            // cout << dist[i][j] << " ";
        }
        // cout << '\n';s
    }
    cout << maxDay;
    return 0;
}