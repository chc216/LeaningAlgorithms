//Z, 골드 5
//재귀 또는 분할정복으로 풀 수 있다. 지금은 재귀를 공부하고 잇으므로 귀납적인 방식을 이용한다
//핵심은 "n=k를 알면 이를 이용하여 n=k+1을 구할 수 있음. 그리고 baseCondition을 구할 수 있음"이다

#include <iostream>
#include <cmath>
using namespace std;

int recur(int n, int a, int b) {
    int half = (int)(pow(2, n) / 2);
    if(n == 0) {
        return 0;
    }
    if(a < half && b < half) {
        return recur(n-1, a, b);
    }
    if(a < half && b >= half) {
        return half*half + recur(n-1, a, b-half);
    }
    if(a >= half && b < half) {
        return 2*half*half + recur(n-1, a-half, b);
    }
    // if(a >= half && b >= half) {
        return 3*half*half + recur(n-1, a-half, b-half);
    // }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << recur(n, r, c);
}