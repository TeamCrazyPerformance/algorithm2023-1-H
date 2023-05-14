// https://velog.io/@skyepodium/백준-14500-테트로미노 에서 가져왔습니다.
#include <iostream>
#define max_int 501
using namespace std; 

int n, m, a[max_int][max_int], result; 
bool check[max_int][max_int];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int ex[4][4] = {{0,0,0,1}, {0,1,2,1}, {0,0,0,-1}, {0,-1,0,1}};
int ey[4][4] = {{0,1,2,1}, {0,0,0,1}, {0,1,2,1}, {0,1,1,1}};

int max(int a, int b) {
	return a > b ? a : b;
}

// DFS로 4가지 모양 검사(ㅜ 제외)
void dfs(int x, int y, int sum_value, int length) {
	// 길이가 4 이상이면 종료해 줍니다.
	if (length >= 4) {
		result = max(result, sum_value); 
		return; 
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

		// 방문하지 않은 점이면 
		if (!check[nx][ny])  {
			// 들어가기 전 체크해주고
			check[nx][ny] = true;

			dfs(nx, ny, sum_value + a[nx][ny], length + 1); 

			// 나올 때 체크를 해제합니다. 
			check[nx][ny] = false; 
		}
	}
}

// ㅜ 모양 검사
void check_exshape(int x, int y) {

	for (int i = 0; i < 4; i++) {

		bool isOut = false; 
		int sum_value = 0; 

		for (int j = 0; j < 4; j++) {
			int nx = x + ex[i][j]; 
			int ny = y + ey[i][j]; 

			if (nx < 1 || nx > n || ny < 1 || ny > m) {
				isOut = true;
				break;
			}
			else {
				sum_value += a[nx][ny]; 
			}
			if (!isOut) {
				result = max(result, sum_value); 
			}
		}
	}
}

int main() {

	// 1. 입력
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]); 
		}
	}

	// 2. 2차원 배열 각각의 원소에서 검사를 수행합니다. 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// DFS 로 검사

			check[i][j] = true;
			dfs(i, j, a[i][j], 1); 
			check[i][j] = false; 

			check_exshape(i,j); 
		}
	}

	printf("%d\n", result);
}