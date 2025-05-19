//골드 4, DSLR
//
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct State {
    int reg;
    string route;
};

char dc[4] = {'D', 'S', 'L', 'R'};
bool vis[10001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        for(int i = 0; i < 10001; i++){
            vis[i] = 0;
        }
        string a,b;
        cin >> a >> b;
        const int goal = stoi(b);
        queue<State> Q;
        vis[stoi(a)] = true;
        Q.push({stoi(a), ""});
        bool flag = false;
        while(!Q.empty() && !flag){
            State cur = Q.front(); Q.pop();
            // cout << "cur number : " << cur.reg << '\n';
            for(int dir = 0; dir < 4; dir++){
                int nextNumber = cur.reg;
                if(dc[dir] == 'D'){
                    if(nextNumber*2 < 9999) nextNumber *= 2;
                    else nextNumber = 2*nextNumber % 10000;
                }
                if(dc[dir] == 'S'){
                    if(nextNumber == 0) nextNumber = 9999;
                    else nextNumber--;
                }
                if(dc[dir] == 'L'){
                    string regString = to_string(cur.reg);
                    string nextString;
                    if(regString.size() == 4) {
                        nextString = regString;
                    }
                    else {
                        for(int i = 0; i < 4 - regString.size(); i++){
                            nextString.append("0");
                        }
                        nextString.append(regString);
                    }////////////////////////////////
                    char tmpChar = nextString[0];
                    nextString[0] = nextString[1];
                    nextString[1] = nextString[2];
                    nextString[2] = nextString[3];
                    nextString[3] = tmpChar;
                    nextNumber = stoi(nextString);
                }
                if(dc[dir] == 'R'){
                    string regString = to_string(nextNumber);
                    string nextString;
                    if(regString.size() == 4) {
                        nextString = regString;
                    }
                    else {
                        for(int i = 0; i < 4 - regString.size(); i++){
                            nextString.append("0");
                        }
                        nextString.append(regString);
                    }
                    char tmpChar = nextString[3];
                    nextString[3] = nextString[2];
                    nextString[2] = nextString[1];
                    nextString[1] = nextString[0];
                    nextString[0] = tmpChar;
                    nextNumber = stoi(nextString);
                }
                if(vis[nextNumber]) continue;
                if(nextNumber == goal) {
                    flag = true;
                    cout << cur.route + dc[dir] << '\n';
                    break;
                }
                Q.push({nextNumber, cur.route + dc[dir]});
                vis[nextNumber] = true;
            }
        }
    }
    return 0;
}
