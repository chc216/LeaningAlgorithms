#include <iostream>
using namespace std;

long long mod(int a, int b, int c){
    if(b == 1)
        return a%c;
    if(b == 0)
        return 1;
    long long result = mod(a,b/2,c) % c;

    if(b%2 == 1){
        return result*result%c*a%c;
    }
    return result*result%c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    long long ans = mod(a,b,c);
    cout << ans;
    return 0;
}