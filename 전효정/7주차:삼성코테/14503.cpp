#include <iostream>
using namespace std; 

int room[51][51];

int main()
{
	int N, M; 
	cin >> N >> M; 

	int r, c;
	int direction; 

	cin >> r >> c >> direction;

	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num; 
			room[i][j] = num; 
		}
	}

	int count = 0;
	while (1) {
		if (room[r][c] == 0) {
			room[r][c] = 2; 
			count++;
		}

		// 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
		if ((r-1 < 0 || room[r-1][c] == 1 || room[r-1][c] == 2) &&
			(c+1 >= M || room[r][c+1] == 1 || room[r][c+1] == 2) &&
			(r+1 >= N || room[r+1][c] == 1 || room[r+1][c] == 2) &&
			(c-1 < 0 || room[r][c-1] == 1 || room[r][c-1] == 2)) {
			// 북쪽을 바라보고 있었더라면.
			if (direction == 0) {
				if (r+1 >= N || room[r+1][c] == 1) break;
				r++;
			}
			// 동쪽을 바라보고 있었더라면.
			if (direction == 1) {
				if (c-1 < 0 || room[r][c-1] == 1) break;
				c--;
			}
			// 남쪽을 바라보고 있었더라면.
			if (direction == 2) {
				if (r-1 < 0 || room[r-1][c] == 1) break;
				r--;
			}
			// 서쪽을 바라보고 있었더라면.
			if (direction == 3) {
				if (c+1 >= M || room[r][c+1] == 1) break;
				c++;
			}
		} else {
			direction--;
			if (direction < 0) direction = 3; 
			// 북쪽을 바라보게 되었더라면.
			if (direction == 0) {
				if (r-1 >= 0 && room[r-1][c] == 0) r--;
			}
			// 동쪽을 바라보게 되었더라면.
			if (direction == 1) {
				if (c+1 < M && room[r][c+1] == 0) c++;
			}
			// 남쪽을 바라보게 되었더라면.
			if (direction == 2) {
				if (r+1 < N && room[r+1][c] == 0) r++;
			}
			// 서쪽을 바라보게 되었더라면.
			if (direction == 3) {
				if (c-1 >= 0 && room[r][c-1] == 0) c--;
			}
		}
	}

	cout << count;
}