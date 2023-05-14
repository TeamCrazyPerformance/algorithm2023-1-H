#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int max_block[6] = {0};

int left(int n, int m, int a, vector<vector<int>> block); // 하나씩 옮기면서 앞에 있는 숫자랑 같으면 합치기
int right(int n, int m, int a, vector<vector<int>> block);
int up(int n, int m, int a, vector<vector<int>> block);
int down(int n, int m, int a, vector<vector<int>> block);

int DFS(int n, int m, int a, vector<vector<int>> block) {
	int r1 = left(n, m, a + 1, block);
	int r2 = right(n, m, a + 1, block);
	int r3 = up(n, m, a + 1, block);
	int r4 = down(n, m, a + 1, block);
	return max(max(r1, r2), max(r3, r4));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> block;
	vector<int> tmp;
	for (int j = 0; j < n; j++) {
		tmp.push_back(0);
	}
	for (int i = 0; i < n; i++) {
		block.push_back(tmp);
	}
	for (int i = 0; i < n; i++) { // 처음 상태
		for (int j = 0; j < n; j++) {
			cin >> block[i][j];
			max_block[0] = max(max_block[0], block[i][j]);
		}
	}
	cout << DFS(n, max_block[0], 0, block);
	return 0;
}

int left(int n, int m, int a, vector<vector<int>> block) {
	int max_tmp = m;
	for (int i = 0; i < n; i++) {
		int cnt = 0, first = 0;
		for (int j = 0; j < n; j++) {
			if (block[i][j]) {
				block[i][cnt] = block[i][j];
				if (j != cnt) block[i][j] = 0;
				if (cnt && !first) {
					if (block[i][cnt - 1] == block[i][cnt]) {
						block[i][cnt - 1] <<= 1;
						max_tmp = max(max_tmp, block[i][cnt - 1]);
						block[i][cnt] = 0;
						first += 2;
						cnt--;
					}
				}
				if (first) first--;
				cnt++;
			}
		}
	}
	max_block[a] = max(max_block[a], max_tmp);
	if (n == 5) {
		return max_tmp;
	}
	if (max_tmp > max_block[5] >> 5 - a) return DFS(n, max_tmp, a, block);
	else return max_block[5];
}

int right(int n, int m, int a, vector<vector<int>> block) {
	int max_tmp = m;
	for (int i = 0; i < n; i++) {
		int cnt = 0, first = 0;
		for (int j = n - 1; j > -1; j--) {
			if (block[i][j]) {
				block[i][n - 1 - cnt] = block[i][j];
				if (j != n - 1 - cnt) block[i][j] = 0;
				if (cnt && !first) {
					if (block[i][n - cnt] == block[i][n - 1 - cnt]) {
						block[i][n - cnt] <<= 1;
						max_tmp = max(max_tmp, block[i][n - cnt]);
						block[i][n - 1 - cnt] = 0;
						first += 2;
						cnt--;
					}
				}
				if (first) first--;
				cnt++;
			}
		}
	}
	max_block[a] = max(max_block[a], max_tmp);
	if (n == 5) {
		return max_tmp;
	}
	if (max_tmp > max_block[5] >> 5 - a) return DFS(n, max_tmp, a, block);
	else return max_block[5];
}

int up(int n, int m, int a, vector<vector<int>> block) {
	int max_tmp = m;
	for (int j = 0; j < n; j++) {
		int cnt = 0, first = 0;
		for (int i = 0; i < n; i++) {
			if (block[i][j]) {
				block[cnt][j] = block[i][j];
				if (i != cnt) block[i][j] = 0;
				if (cnt && !first) {
					if (block[cnt - 1][j] == block[cnt][j]) {
						block[cnt - 1][j] <<= 1;
						max_tmp = max(max_tmp, block[cnt - 1][j]);
						block[cnt][j] = 0;
						first += 2;
						cnt--;
					}
				}
				if (first) first--;
				cnt++;
			}
		}
	}
	max_block[a] = max(max_block[a], max_tmp);
	if (n == 5) {
		return max_tmp;
	}
	if (max_tmp > max_block[5] >> 5 - a) return DFS(n, max_tmp, a, block);
	else return max_block[5];
}

int down(int n, int m, int a, vector<vector<int>> block) {
	int max_tmp = m;
	for (int j = 0; j < n; j++) {
		int cnt = 0, first = 0;
		for (int i = n - 1; i > -1; i--) {
			if (block[i][j]) {
				block[n - 1 - cnt][j] = block[i][j];
				if (i != n - 1 - cnt) block[i][j] = 0;
				if (cnt && !first) {
					if (block[n - cnt][j] == block[n - 1 - cnt][j]) {
						block[n - cnt][j] <<= 1;
						max_tmp = max(max_tmp, block[n - cnt][j]);
						block[n - 1 - cnt][j] = 0;
						first += 2;
						cnt--;
					}
				}
				if (first) first--;
				cnt++;
			}
		}
	}
	max_block[a] = max(max_block[a], max_tmp);
	if (n == 5) {
		return max_tmp;
	}
	if (max_tmp > max_block[5] >> 5 - a) return DFS(n, max_tmp, a, block);
	else return max_block[5];
}
