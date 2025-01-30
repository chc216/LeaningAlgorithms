#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);
	int input;
	cin >> input;
	string word = to_string(input);
	for(char c : word) {
		cnt[c - '0']++;
	}
	
	int tmp = cnt[9] + cnt[6];
	cnt[9] = 0;
	cnt[6] = 0;
	
	if(tmp % 2 == 0)
		tmp /= 2;
	else{
		tmp /= 2;
		tmp++;
	}
	cnt[6] = tmp;
	
	int max = 0;
	for(int i : cnt) {
		if(i > max){
			max = i;
		}
	}
	cout << max;
	
	return 0;
}