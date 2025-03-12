//안전영역 실버 1
//영역 개수 구하는 문제
#include <iostream>
#include <queue>
#include <utility>
#include <climits>
#define X first
#define Y second
using namespace std;

int board[101][101];
bool vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // int min = 100;
    // int max = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            // if(board[i][j] < min) min = board[i][j];
            // if(board[i][j] > max) max = board[i][j];
        }
    }
    // cout << "min :" << min <<'\n';
    // cout << "max :" << max <<'\n';

    int max_cnt = INT_MIN;
    for(int piv = 0; piv <= 100; piv++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] > piv && vis[i][j] == 0){
                    queue<pair<int, int>> Q;
                    cnt++;
                    Q.push({i, j});
                    vis[i][j] = 1;
                    while(!Q.empty()){
                        pair<int, int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int x = cur.X + dx[dir];
                            int y = cur.Y + dy[dir];
                            if(x < 0 || x >= n || y < 0 || y >= n) continue;
                            if(vis[x][y] || board[x][y] <= piv) continue;
                            Q.push({x, y});
                            vis[x][y] = 1;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                vis[i][j] = 0;
            }
        }
        if(cnt > max_cnt) max_cnt = cnt;
    }
    cout << max_cnt;
    return 0;
    
}