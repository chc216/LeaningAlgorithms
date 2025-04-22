//불! 골드 3
//멀티소스 bfs + 조건 추가 유형
//필수적으로 고민해야할 지점 세가지
//1. 어떤 유형인가?
//2. 큐에는 어떤 정보를 저장해야하는가? 좌표만?좌표+상태?
//3. 기록하는 배열은 어떤 배열을 사용해야하는가?dist?vis?

#include <iostream>
#include <utility>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;
const int MAX = 1000;
string board[MAX];
int fireDist[MAX][MAX];
int jihunDist[MAX][MAX];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0 , -1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    queue<pair<int, int>> Qf;
    queue<pair<int, int>> Qj;
    for(int i = 0; i < r; i++){
        cin >> board[i];
        for(int j = 0; j < c; j++){
            fireDist[i][j] = -1; jihunDist[i][j] = -1;
            if(board[i][j] == 'F'){
                Qf.push({i, j});
                fireDist[i][j] = 1;
            }
            if(board[i][j] == 'J'){
                Qj.push({i, j});
                jihunDist[i][j] = 1;
            }
        }
    }

    while(!Qf.empty()){
        pair<int, int> cur = Qf.front(); Qf.pop();
        int x = cur.X;
        int y = cur.Y;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '#' || board[nx][ny] == 'J' || fireDist[nx][ny] > 0) continue;
            Qf.push({nx, ny});
            fireDist[nx][ny] = fireDist[x][y] + 1;
        }
    }

    while(!Qj.empty()){
        pair<int, int> cur = Qj.front(); Qj.pop();
        int x = cur.X;
        int y = cur.Y;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << jihunDist[x][y];
                return 0;
            }
            if(board[nx][ny] == 'F' || board[nx][ny] == '#' || jihunDist[nx][ny] != -1) continue;
            if(fireDist[nx][ny] != -1 && (jihunDist[x][y] + 1 >= fireDist[nx][ny])) continue;
            Qj.push({nx, ny});
            jihunDist[nx][ny] = jihunDist[x][y] + 1;
        }
    }
    cout << "IMPOSSIBLE";
}