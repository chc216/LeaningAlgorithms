//5014 스타트링크 실버1
//문제 유형: 단일 소스 최단거리 문제
//거리를 기록하면서 탐색하기
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int vis[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;

    for(int i = 1; i <= f; i++){
        vis[i] = -1;
    } //vis 초기화

    queue<int> Q;
    Q.push(s);
    vis[s] = 0; //init

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int down_side = cur - d;
        if(down_side >= 1 && down_side <= f){
            if(vis[down_side] == -1 || vis[down_side] > vis[cur] + 1){
                vis[down_side] = vis[cur] + 1;
                Q.push(down_side);
            }
        }

        int up_side = cur + u;
        if(up_side >= 1 && up_side <= f){
            if(vis[up_side] == -1 || vis[up_side] > vis[cur] + 1){
                vis[up_side] = vis[cur] + 1;
                Q.push(up_side);
            }
        }
    }
    // for(int i = 1; i <= f; i++){
    //     cout << vis[i] << " ";
    // }

    if(vis[g] == -1){
      cout << "use the stairs";
      return 0;
    } 
    else {
        cout << vis[g];
        return 0;
    }
}