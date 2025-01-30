#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
	string word;
	cin >> word;
	for(char c : word) {
		cnt[c - 'a']++;
	}
	for(int i : cnt)
		cout << i << ' ';
	return 0;
}
