//하노이 탑 이동 순서, 골드 5
#include <iostream>
#include <cmath>
using namespace std;

void recur(int a, int b, int n){
    if(n == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    recur(a, 6-a-b, n-1);
    cout << a << " " << b << '\n';
    recur(6-a-b, b, n-1);
}

int main() {
    int n;
    cin >> n;
    int cnt = (int)pow(2, n) - 1;
    cout << cnt << '\n';
    recur(1,3,n);
}
