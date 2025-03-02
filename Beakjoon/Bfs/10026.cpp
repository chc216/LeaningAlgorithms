//10026 적록색약 골드 5
//bfs 두번 돌리면 됨(일반인 버전 1, 적록색약 1) + 영역  개수 세기

#include <iostream>
#include <utility>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;

string board[101];
bool vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 0) {
                queue<pair<int, int>> Q;
                Q.push({i,j});
                vis[i][j] = 1;
                cnt++;
                while(!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];
                        if(x < 0 || x >= n || y < 0 || y >= n) continue;
                        if(vis[x][y] || board[x][y] != board[cur.X][cur.Y]) continue;
                        Q.push({x,y});
                        vis[x][y] = 1;
                    }
                }
            }
        }
    }
    cout << cnt << ' ';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'R' || board[i][j] == 'G')
                board[i][j] = 'R';
            vis[i][j] = 0;
        }
    }
    
    cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 0) {
                queue<pair<int, int>> Q;
                Q.push({i,j});
                vis[i][j] = 1;
                cnt++;
                while(!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];
                        if(x < 0 || x >= n || y < 0 || y >= n) continue;
                        if(vis[x][y] || board[x][y] != board[cur.X][cur.Y]) continue;
                        Q.push({x,y});
                        vis[x][y] = 1;
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;

}