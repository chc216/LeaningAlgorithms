//상범 빌딩, 골드 5
//3차원 배열에서의 단일 소스 최단 거리 문제

//1. 탈출 조건 부재로 인해 BFS를 배열 전체를 돌리게 되므로 메모리 초과
//1-1 탈출 조건은 1. bfs를 다 돌리고 나서 출구의 dis기록을 보거나, 2. 출구 좌표를 만날 때 바로 탈출하는것. 1의 방법을 사용하면 큐가 터진다.
//2. 3차원 배열에서 튜플 사용의 부재
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int dz[6] = {1,-1, 0, 0, 0, 0};
int dx[6] = {0,0, 1, 0, -1, 0};
int dy[6] = {0,0, 0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, r, c;
    while(true) {
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0)
            break;
        char board[31][31][31];
        int dis[31][31][31];
        queue<tuple<int, int, int>> Q;
        tuple<int, int, int> E = {-1,-1,-1};
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> board[i][j][k];
                    dis[i][j][k] = -1;
                    if(board[i][j][k] == 'S'){
                        Q.push({i,j,k});
                        dis[i][j][k] = 0;
                    }
                    if(board[i][j][k] == 'E'){
                        E = {i,j,k};
                    }
                }
            }
        }

        while(!Q.empty()){
            auto [curZ, curX, curY] = Q.front(); Q.pop();
            for(int dir = 0; dir < 6; dir++){
                int z = curZ + dz[dir];
                int x = curX + dx[dir];
                int y = curY + dy[dir];
                if(z < 0 || z >= l || x < 0 || x >= r || y < 0 || y >= c) continue;
                if(dis[z][x][y] != -1 || board[z][x][y] == '#') continue;
                Q.push({z,x,y});
                dis[z][x][y] = dis[curZ][curX][curY] + 1;
            }
        }

        auto [exitZ, exitX, exitY] = E;
        if(dis[exitZ][exitX][exitY] == -1){
            cout << "Trapped!\n";
        }
        else{
            cout << "Escaped in " << dis[exitZ][exitX][exitY] << " minute(s).\n";
        }   
    }
    return 0;
}