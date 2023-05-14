// https://dingcoding.tistory.com/85 에서 가져 왔습니다.
#include <bits/stdc++.h>
using namespace std;

int arr[40][40], n, m, h, ans=INT_MAX, target_cnt;

// 사다리타기 체크
bool check() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (start + 1 <= n && arr[j][start] == true) {
				start++;
			}
			else if (start-1 >= 1 && arr[j][start-1] == true) {
				start--;
			}
		}
		if (start != i) return false; 
	}
	return true;
}

void DFS(int h_cnt, int n_cnt, int cnt) {

	// 사다리 선택하는 횟수를 통해 가지치기 하기
	if (cnt == target_cnt) {
		if (check()) {
			ans = cnt; 
		}
		return;
	}

	// 매개변수 설정을 잘 해주면 이전에 돌았던 거 다시 안돌아도 되어서
	// 가지치기를 할 수 있다. 
	for (int i = h_cnt; i <= h; i++, n_cnt =1 ) {
		for (int j = n_cnt; j < n; j++) {
			// 연속된 사다리 선택 피해주기
			if (arr[i][j-1] || arr[i][j] || arr[i][j+1]) continue;
			else {
				arr[i][j] = 1;
				DFS(i, j, cnt+1); 
				arr[i][j] = 0; 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = true;
	}

	for (int i = 0; i <= 3; i++) {
		target_cnt = i;
		DFS(1,1,0);

		if (ans != INT_MAX) {
			cout << ans;
			return 0; 
		}
	}

	cout << -1;
	return 0; 
}