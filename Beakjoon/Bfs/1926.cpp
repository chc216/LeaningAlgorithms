#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second

int n, m;
int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    int cnt = 0;
    int max_size = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            queue<pair<int, int>> Q;
            if(board[i][j] == 1 && vis[i][j] == 0){
                cnt++;
                int tmp_size = 1;
                Q.push({i, j});
                vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];
                        if(x < 0 || x >= n || y < 0 || y >= m) continue;
                        if(board[x][y] != 1 || vis[x][y]) continue;
                        Q.push({x, y});
                        tmp_size++;
                        vis[x][y] = 1;
                    }
                }
                if(tmp_size > max_size)
                    max_size = tmp_size;
            }
        }
    }
    cout << cnt << '\n' << max_size;
    return 0;
}