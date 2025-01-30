#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	string word = to_string(a*b*c);
	for(char c : word){
		cnt[c-'0']++;
	}
	
	for(int i : cnt) {
		cout << i << '\n';
	}
	return 0;
}