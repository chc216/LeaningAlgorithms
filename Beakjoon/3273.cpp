#include <bits/stdc++.h>
using namespace std;

int freq[2000000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int len;
	cin >> len;
	for(int i = 0; i<len; i++){
		int tmp;
		cin >> tmp;
		freq[tmp]++;
	}
	
	int x;
	int cnt = 0;
	cin >> x;
	//고려해야할 것(반례): x=4인데 2,2일때. 숫자 쌍이 중복돼서 나올때 1,2  1,2.
	for(int i = 1; i < x; i++){
		if(i == x-i){
			cnt += freq[i]/2;
			freq[i] = 0; 
		}
		if(freq[i] >= 1 && freq[x-i] >= 1){
			if(freq[i] <= freq[x-i]){
				cnt += freq[i];
			}
			else{
				cnt += freq[x-i];
			}
			freq[i] = 0;
			freq[x-i] = 0;
		}
	}
	
	cout << cnt;
	return 0;
}