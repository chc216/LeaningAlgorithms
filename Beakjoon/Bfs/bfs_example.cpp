//bfs 기본 틀 코드 예제 연습
//주의 해야할 점
// 1. sync_with_stdio(0), cin.tie(0) 꼭 추가하기
// 2. 방문표시는 큐에 PUSH할 때 기록할 것. POP에 기록하면 에러 가능성.

// #inlcude <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };
bool vis[502][502];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int n = 7, m = 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << cur.X << " " << cur.Y << '\n';
        for(int dir = 0; dir < 4; dir++){
            int x = cur.X + dx[dir];
            int y = cur.Y + dy[dir];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(vis[x][y] == 1 || board[x][y] != 1) continue;
             //한국어로 표현할 때 논리에 맞게 "board가 1이 아닐때" 로 표현함.
            vis[x][y] = 1;
            Q.push({x, y});
        }
    }
    return 0;
}