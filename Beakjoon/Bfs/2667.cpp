//단지번호붙이기 실버 1
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
string board[26];
bool vis[26][26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    // cout << "!!";
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    
    vector<int> answer;
    int cnt = 0;
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '1' && vis[i][j] == 0) {
                int tmp_size = 0;
                Q.push({i, j});
                vis[i][j] = 1;
                cnt++;
                tmp_size++;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];
                        if(x < 0 || x >= n || y < 0 || y >= n) continue;
                        if(board[x][y] == '0' || vis[x][y] == 1) continue;
                        Q.push({x, y});
                        vis[x][y] = 1;
                        tmp_size++;
                    }
                }
                answer.push_back(tmp_size);
            }
        }
    }
    sort(answer.begin(), answer.end(), less<int>());
    cout << cnt <<'\n';
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << '\n';
    }
    return 0;
}