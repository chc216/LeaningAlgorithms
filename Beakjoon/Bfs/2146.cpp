//골드 3 다리만들기
//bfs, 시뮬레이션, flood fill

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;

int board[100][100];
int island[100][100];
bool startPoint[100][100];
int dis[100][100];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  int tmp_vis[n][n];
  memset(tmp_vis, 0, sizeof(tmp_vis));
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0 || tmp_vis[i][j] == 1)
        continue;
      cnt++;
      // cout << cnt;
      queue<pair<int, int>> Q;
      Q.push({i, j});
      island[i][j] = cnt;
      tmp_vis[i][j] = 1;
      while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
          if (board[nx][ny] == 0) {
            startPoint[cur.X][cur.Y] = true;
            continue;
          }
          if (tmp_vis[nx][ny] == 1)
            continue;
          Q.push({nx, ny});
          tmp_vis[nx][ny] = 1;
          island[nx][ny] = cnt;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dis[i][j] == 0 && startPoint[i][j]) {
        int min_dist = 0x7fffffff;
        int tmp_dis[n][n];
        memset(tmp_dis, 0, sizeof(tmp_dis));
        queue<pair<int, int>> Q;
        Q.push({i, j});
        tmp_dis[i][j] = 1;
        while (!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
            if (island[nx][ny] == island[i][j])
              continue;
            if (tmp_dis[nx][ny])
              continue;
            if (island[nx][ny] == 0) {
              Q.push({nx, ny});
              tmp_dis[nx][ny] = tmp_dis[cur.X][cur.Y] + 1;
              continue;
            }
            if (island[nx][ny] > 0 && startPoint[nx][ny]) {
              min_dist = min(min_dist, tmp_dis[cur.X][cur.Y] + 1);
              continue;
            }
          }
        }
        dis[i][j] = min_dist;
      }
    }
  }

  int ans = 0x7fffffff;
  // cout << dis[0][0];
  // cout << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // cout << dis[i][j] << " ";
      if (startPoint[i][j] && dis[i][j] > 0)
        ans = min(ans, dis[i][j]);
    }
    // cout << '\n';
  }
  // cout << '\n';
  // cout << '\n';
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << startPoint[i][j] << " ";
  //   }
  //   cout << '\n';
  // }

  cout << ans - 2;
}