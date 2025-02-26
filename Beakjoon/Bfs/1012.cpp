//유기농 배추 실버 2
//bfs를 이용하여 인접한 영역개수 세기
// 입력값의 n, m을 거꾸로 줌으로서 헷갈리게 함정을 팜
//테스트 케이스 마다 초기화해줘야함(까먹음;;)
#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second
using namespace std;
bool board[51][51];
bool vis[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        
        int n, m, k;
        cin >> m >> n >> k;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                    queue<pair<int, int>> Q;
                    Q.push({i, j}); vis[i][j]=1;
                    while(!Q.empty()){
                        pair<int, int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int x = cur.X + dx[dir];
                            int y = cur.Y + dy[dir];
                            if(x < 0 || x >= n || y < 0 || y >= m) continue;
                            if(board[x][y] != 1 || vis[x][y] == 1) continue;
                            Q.push({x,y});
                            vis[x][y] = 1;
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
