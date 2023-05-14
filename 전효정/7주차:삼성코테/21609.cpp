#include <iostream>
#include <queue>
#include <cmath>
using namespace std; 

int N, M; 
int grid[21][21];
int rotateArray[21][21]; 
int visited[21][21];
int rainbow;
queue<pair<int, int> > que;

void initialize() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0; 
		}
	}
}

void rainbowBlock() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 0) visited[i][j] = 0; 
		}
	}
}

int bfs(int row, int col, bool remove) {

	int num = 0;
	int val = grid[row][col];
	if (val != 0) num++;
	visited[row][col] = 1;
	que.push(make_pair(row, col)); 
	int count = 1; 

	if (grid[row][col] == 0) rainbow++;
	if (remove) grid[row][col] = -2;


	while (!que.empty()) {
		row = que.front().first; 
		col = que.front().second; 

		// 북
		if (row - 1 >= 0 && visited[row-1][col] == 0 && (grid[row-1][col] == val || grid[row-1][col] == 0)) {
			if (grid[row-1][col] == val) num++;
			que.push(make_pair(row-1, col)); 
			visited[row-1][col] = 1;
			count++;
			
			if (grid[row-1][col] == 0) rainbow++;
			if (remove) grid[row-1][col] = -2;
		}
		// 동
		if (col + 1 < N && visited[row][col+1] == 0 && (grid[row][col+1] == val || grid[row][col+1] == 0)) {
			if (grid[row][col+1] == val) num++;
			que.push(make_pair(row, col+1)); 
			visited[row][col+1] = 1;
			count++;
			
			if (grid[row][col+1] == 0) rainbow++;
			if (remove) grid[row][col+1] = -2;
		}

		// 남
		if (row + 1 < N && visited[row+1][col] == 0 && (grid[row+1][col] == val || grid[row+1][col] == 0)) {
			if (grid[row+1][col] == val) num++;
			que.push(make_pair(row+1, col)); 
			visited[row+1][col] = 1;
			count++;
		
			if (grid[row+1][col] == 0) rainbow++;
			if (remove) grid[row+1][col] = -2;
		}

		// 서
		if (col - 1 >= 0 && visited[row][col-1] == 0 && (grid[row][col-1] == val || grid[row][col-1] == 0)) {
			if (grid[row][col-1] == val) num++;
			que.push(make_pair(row, col-1)); 
			visited[row][col-1] = 1;
			count++;

			if (grid[row][col-1] == 0) rainbow++;
			if (remove) grid[row][col-1] = -2;
		}

		que.pop(); 
	}

	if (num >= 1 && count >= 2) return count;
	return -1;

}

void gravity() {
	int k; 
	
	// 위에서 아래	
	for (int j = 0; j < N; j++) {
		for (int i = N-2; i >= 0; i--) {
			if (grid[i][j] == -1 || grid[i][j] == -2) continue;
			k = i;
			while (k+1 <= N && grid[k+1][j] == -2) k++;
			grid[k][j] = grid[i][j];
			if (k != i) grid[i][j] = -2;
		}
	}
}

void rotate() {
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			rotateArray[N-col-1][row] = grid[row][col];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			grid[i][j] = rotateArray[i][j]; 
		}
	}
}



int main()
{
	cin >> N >> M; 

	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num; 
			grid[i][j] = num; 
		}
	}

	int maxVal;
	int maxRow, maxCol;
	int bfsVal;

	int result = 0;

	while (1) {

		initialize();
		bool flag = true; 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j] == 0 || grid[i][j] == -1 || grid[i][j] == -2 || visited[i][j] == 1) continue;
				if(bfs(i, j, false) != -1) {
					flag = false; 
				}
			}
		}

		if (flag) break;

		maxVal = 0; 
		int maxRainbow = 0;

		maxRow = -1, maxCol = -1;
		initialize();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rainbow = 0;
				if (grid[i][j] == 0 || grid[i][j] == -1 || grid[i][j] == -2 || visited[i][j] == 1) continue;
				
				bfsVal = bfs(i, j, false);
				rainbowBlock();

				if (bfsVal == maxVal) {
					if (rainbow > maxRainbow) {
						maxRow = i; 
						maxCol = j; 
						maxRainbow = rainbow;
					}
				}
				else if (bfsVal > maxVal) {
					maxVal = bfsVal;
					maxRow = i; 
					maxCol = j; 
				}
			}
		}

		if (maxRow == -1) continue;


		initialize();
		int sum = pow(bfs(maxRow, maxCol, true), 2);
		result += sum; 

		gravity();
		rotate();
		gravity();

	}

	cout << result; 
}