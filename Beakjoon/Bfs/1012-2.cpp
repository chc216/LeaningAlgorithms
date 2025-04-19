//bfs연습용 재풀이
//입력 : 테스트케이스, 배열 범위, 배추 좌표
//출력 : 배추 구역 개수
#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second
using namespace std;

bool board[502][502];
bool vis[502][502];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> m >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        int K;
        cin >> K;
        for(int i = 0; i < K; i++){
            int tmpX, tmpY;
            cin >> tmpY >> tmpX;
            board[tmpX][tmpY] = 1;
        }
        
        int answer = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && board[i][j] == 1) {
                    queue<pair<int, int>> Q;
                    Q.push({i, j});
                    answer++;
                    vis[i][j] = 1;
                    while(!Q.empty()){
                        pair<int, int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        cout << answer << '\n';
    }
    return 0;
}