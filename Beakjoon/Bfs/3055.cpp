//탈출 골드 4
//멀티소스 bfs이지만 불! 에 비해 탈출 조건이 미묘하게 달라진 유형
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
const int MAX = 50;
string board[MAX];
int s_dist[MAX][MAX];
int w_dist[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    pair<int, int> goal;
    queue<pair<int, int>> s_Q;
    queue<pair<int, int>> w_Q;
    for(int i = 0; i < r; i++){
        cin >> board[i];
        for(int j = 0; j < c; j++){
            if(board[i][j] == 'S'){
                // cout << "!!!!";
                s_Q.push({i, j});
                s_dist[i][j] = 1;
            }
            if(board[i][j] == '*'){
                w_Q.push({i, j});
                w_dist[i][j] = 1;
            }
            }
        }

    while(!w_Q.empty()){
        pair<int, int> cur = w_Q.front(); w_Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == 'D' || board[nx][ny] == 'X' || w_dist[nx][ny] != 0) continue;
            w_Q.push({nx, ny});
            w_dist[nx][ny] = w_dist[cur.X][cur.Y] + 1;
        }
    }

    while(!s_Q.empty()){
        pair<int, int> cur = s_Q.front(); s_Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == 'D'){
                cout << s_dist[cur.X][cur.Y];
                return 0;
            }
            if(board[nx][ny] == 'X' || s_dist[nx][ny] != 0) continue;
            if(w_dist[nx][ny] != 0 && w_dist[nx][ny] <= s_dist[cur.X][cur.Y] + 1) continue;
            s_Q.push({nx, ny});
            s_dist[nx][ny] = s_dist[cur.X][cur.Y] + 1;
        }
    }

    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j++){
    //         cout << s_dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << "KAKTUS";
    return 0;

}