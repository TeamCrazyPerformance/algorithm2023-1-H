#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tetris[501][501]; 
int visited[501][501];
vector<int> v;
int N, M; 
int maxVal = 0;

void initialize() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0; 
		}
	}
}

void maxTetris(int row, int col) {

	if (v.size() == 4) {
		int ret = 0;
		for (int i = 0; i < v.size(); i++) {
			ret += v[i];
		}
		if (ret > maxVal) maxVal = ret;
		return; 
	}	

	// 북쪽
	if (row - 1 >= 0 && visited[row-1][col] == 0) {
		v.push_back(tetris[row-1][col]);
		visited[row-1][col] = 1;
		maxTetris(row-1, col);
		visited[row-1][col] = 0;
		v.pop_back(); 
	}

	// 동쪽
	if (col + 1 < M && visited[row][col+1] == 0) {
		v.push_back(tetris[row][col+1]); 
		visited[row][col+1] = 1;
		maxTetris(row, col+1);
		visited[row][col+1] = 0;
		v.pop_back(); 
	}
	// 남쪽
	if (row + 1 < N && visited[row+1][col] == 0) {
		v.push_back(tetris[row+1][col]); 
		visited[row+1][col] = 1;
		maxTetris(row+1, col);
		visited[row+1][col] = 0;
		v.pop_back();
	}
	// 서쪽
	if (col - 1 >= 0 && visited[row][col-1] == 0) {
		v.push_back(tetris[row][col-1]); 
		visited[row][col-1] = 1;
		maxTetris(row, col-1);
		visited[row][col-1] = 0;
		v.pop_back();
	}
}

void wooShape(int row, int col) {
	int ans;
	// ㅜ
	if (col-1 >= 0 && col+1 < M && row+1 < N) {
		ans = tetris[row][col] + tetris[row][col-1] + tetris[row][col+1] + tetris[row+1][col];
		maxVal = max(maxVal, ans);
	}
	// ㅏ
	if (row-1 >= 0 && row+1 < N && col+1 < M) {
		ans = tetris[row][col] + tetris[row-1][col] + tetris[row+1][col] + tetris[row][col+1];
		maxVal = max(maxVal, ans);
	}
	// ㅗ
	if (row-1 >= 0 && col-1 >= 0 && col+1 < M) {
		ans = tetris[row][col] + tetris[row-1][col] + tetris[row][col-1] + tetris[row][col+1];
		maxVal = max(maxVal, ans);
	}

	// ㅓ
	if (row-1 >= 0 && row+1 < N && col-1 >= 0) {
		ans = tetris[row][col] + tetris[row-1][col] + tetris[row+1][col] + tetris[row][col-1];
		maxVal = max(maxVal, ans);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M; 

	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			tetris[i][j] = num;
		}
	}

	int maxResult = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			initialize(); 
			maxVal = 0; 
			wooShape(i,j);
			v.push_back(tetris[i][j]);
			visited[i][j] = 1;
			maxTetris(i,j); 
			maxResult = max(maxResult, maxVal);
			visited[i][j] = 0; 
			v.pop_back();
		}
	}

	cout << maxResult;
}