//골드 3 텀프로젝트
// ??? BFS문제로 나왔는데 어디에 적용되는지 아리송 -> vis배열에 기록하는 부분에서 bfs

#include <iostream>
#include <queue>
using namespace std;
int board[100001];
bool vis[100001];
bool isCycle[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            vis[i] = 0;
            isCycle[i] = 0;
            cin >> board[i];
        }

        for(int piv = 1; piv <= n; piv++){
            queue<int> Q;
            if(vis[piv] == 1) continue;
            int start = piv;
            int cur = piv;
            int nxt = board[cur];
            

            vis[cur] = 1;
            isCycle[cur] = 1;
            Q.push(cur);
            
            // if(vis[nxt] == 1 && nxt != cur){ //싸이클 뒤에 붙어지는 정점 전용 예외처리
            //     isCycle[cur] = 0;
            //     vis[cur] = 1;
            //     continue;
            // }
            //1. 
            while(vis[nxt] != 1){
                cur = nxt;
                nxt = board[cur];
                vis[cur] = 1;
                isCycle[cur] = 1;
                Q.push(cur);
            }


            while(!Q.empty() && Q.front() != nxt){
                isCycle[Q.front()] = 0;
                Q.pop();
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(isCycle[i] == 0) cnt++;
            // cout << isCycle[i] << " ";
        }
        cout << cnt << '\n';
    }
    return 0;
}