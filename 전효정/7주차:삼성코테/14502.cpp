#include <iostream>
#include <queue>
using namespace std;

int virusMap[9][9];
int visited[9][9];
int N, M; 
queue<pair<int, int> > que;

void initialize() {
	while (!que.empty()) que.pop(); 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = virusMap[i][j]; 
			if (virusMap[i][j] == 2) que.push(make_pair(i,j)); 
		}
	}
}

int spreadVirus(int count) {

	if (count == 3) {
		// BFS
		while (!que.empty()) {
			int row = que.front().first;
			int col = que.front().second; 
			visited[row][col] = 2;
			// 북쪽
			if (row-1 >= 0 && visited[row-1][col] == 0) {
				visited[row-1][col] = 2;
				que.push(make_pair(row-1,col));
			}
			// 동쪽
			if (col+1 < M && visited[row][col+1] == 0) {
				visited[row][col+1] = 2;
				que.push(make_pair(row,col+1));
			}
			// 남쪽
			if (row+1 < N && visited[row+1][col] == 0) {
				visited[row+1][col] = 2;
				que.push(make_pair(row+1,col));
			}
			// 서쪽
			if (col-1 >= 0 && visited[row][col-1] == 0) {
				visited[row][col-1] = 2;
				que.push(make_pair(row,col-1));
			}
			que.pop(); 
		}

		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == 0) result++;
			}
		}
		
		initialize();
		return result; 
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virusMap[i][j] == 0) {
				virusMap[i][j] = 1; 
				result = max(result, spreadVirus(++count));
				virusMap[i][j] = 0;
				count--;
			}
		}
	}
	return result;
}

int main()
{
	cin >> N >> M; 
	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num; 
			if (num == 2) {
				que.push(make_pair(i, j)); 
			}
			virusMap[i][j] = num; 
		}
	}
	cout << spreadVirus(0);
}