//숨바꼭질 4 골드 4
// 최단 거리 + 경로 출력 유형
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 100001;
int dis[MAX];
int from[MAX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    Q.push(n);
    dis[n] = 1;
    from[n] = n;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == k){
                cout << dis[k] - 1 << '\n';
                int j = k;
                stack<int> ans;
                while(j != n){
                    ans.push(j);
                    j = from[j];
                }
                ans.push(j);
                while(!ans.empty()){
                    cout << ans.top() << " ";
                    ans.pop();
                }
                return 0;
            }
        for(int i = 0; i < 3; i++){
            int nxt;
            if(i == 0){
                nxt = cur + 1;    
            }
            if(i == 1){
                nxt = cur - 1;
            }
            if(i == 2){
                nxt = cur * 2;
            }
            if(nxt >= MAX || nxt < 0) continue;
            if(dis[nxt] && dis[nxt] < dis[cur] + 1) continue;
            Q.push(nxt);
            dis[nxt] = dis[cur] + 1;
            from[nxt] = cur;
            
        }
    }
    
}