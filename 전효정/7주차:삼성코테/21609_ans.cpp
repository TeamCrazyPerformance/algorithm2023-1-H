// https://kimjingo.tistory.com/199 에서 가져 왔습니다
#include <vector>
#include <iostream>
#include <queue>

using namespace std; 
int N, M; 
vector<vector<int> > board; 
enum {
	RAINBOW = 0, BLACK = -1, EMPTY = -2
};
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int score = 0; // 획득한 점수
vector<pair<int, int> > best_blocks; // 가장 적합한 블록
int best_rainbows; // 가장 적합한 블록의 무지개 블록 수
int best_start_y; // 가장 적합한 블록의 시작 Y 좌표
int best_start_x; // 가장 적합한 블록의 시작 X 좌표

vector<vector<bool> > used; // 방문 기록용 벡터(BFS에서 사용)

void pboard() {
	for (size_t i = 0; i < board.size(); i++) {
		for (size_t j = 0; j < board.size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl; 
	}
	cout << endl; 
}

bool compare_block_groups(vector<pair<int, int> > blocks, int rainbows, 
	int start_y, int start_x) {
	// * 블록 비교 방법에 따라 블록 비교
	// 크기가 가장 큰 블록 그룹을 찾는다.
	// 그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹, 
	// 그러한 브록도 여러 개라면 기준 블록의 행이 가장 큰 것을, 그것도 여러개이면 열이 가장 큰 것을 찾는다.

	if (best_blocks.size() < blocks.size()) {
		return true;
	}
	else if (best_blocks.size() == blocks.size()) {
		if (best_rainbows < rainbows) return true; 
		else if (best_rainbows == rainbows) {
			if (best_start_y < start_y) return true;
			else if (best_start_x < start_x) return true;
		}
	}
	return false; 
}

void bfs(int y, int x, int block_number) {
	// bfs 를 이용하여 가장 큰 블록그룹 탐색

	queue<pair<int, int> > q; // Queue
	vector<pair<int, int> > rainbows // 무지개 블록 좌표 저장 용도
	vector<pair<int, int> > blocks; // 블록 그룹 좌표 저장 용도

	q.push(make_pair(y, x));
	blocks.push_back(make_pair(y, x)); 
	used[y][x] = true; 

	while (!q.empty()) {
		int sy = q.front().first; 
		int sx = q.front().second; 
		q.pop(); 

		// 4방향 탐색
		for (int d = 0; d < 4; d++) {
			int ny = sy + dy[d]; 
			int nx = sx + dx[d]; 
			
			// 범위를 벗어났거나 사용한 경우.
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || used[ny][nx]) continue; 
			else if (board[ny][nx] == block_number || board[ny][nx] == RAINBOW) {
				// 블록 번호가 같거나 무지개 블록인 경우
				blocks.push_back(make_pair(ny, nx)); 
				q.push(make_pair(ny, nx));
				used[ny][nx] = true; 
				if (board[ny][nx] == RAINBOW) // 무지개 블록은 무지개 블록 리스트에 추가
					rainbows.push_back(make_pair(ny, nx)); 
			}
		}
	}
	if (compare_block_groups(blocks, rainbows.size(), y, x)) {
		// 블록 비교 결과 현재 탐색한 블록이 우세한 경우
		best_blocks = blocks;
		best_rainbows = rainbows.size(); 
		best_start_y = y; 
		best_start_x = x;
	}

	// 무지개 블록은 중복해서 사용하므로 무지개블록 좌표들의 used(사용 여부)를 false 로 변경
	for (int i = 0; i < rainbows.size(); i++) {
		int sy = rainbows[i].first; 
		int sx = rainbows[i].second;
		used[sy][sx] = false; 
	}
}

bool find_largest_block_group() {
	// 가장 큰 블록 그룹을 찾는 함수

	used = vector<vector<bool> > (N, vector<bool>(N, false)); 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!used[i][j] && board[i][j] > 0) // 사용하지 않았고, 일반 블록인 경우 (>0)
				bfs(i, j, board[i][j]); 
		}
	}
	// 가장 큰 블록 그룹의 크기가 1보다 큰 경우 True, 같거나 작은 경우 False
	// 알고리즘 종료 조건: 가장 큰 블록 그룹 크기가 2보다 작은 경우
	return best_blocks.size() > 1; 
}

void delete_best_block_group() {
	// 가장 큰 블록 그룹 삭제 및 점수 획득
	for (int i = 0; i < best_blocks.size(); i++) {
		int y = best_blocks[i].first; 
		int x = best_blocks[i].second; 
		board[y][x] = EMPTY; 
	}
	score += best_blocks.size() * best_blocks.size(); i

	// 블록 그룹을 사용했으므로, 가장 큰 블록 그룹 정보 초기화
	best_blocks.clear();
	best_rainbows = best_start_y = best_start_x = 0; 
}

void work_gravity() {
	// 중력 작용
	for (int i = N-2; i >= 0; i--) { // N-2부터 0까지 탐색 (마지막 행으로부터 첫번째의 행부터 줄여가며)
		for (int j = 0; j < N; j++) {
			if (board[i][j] == EMPTY || board[i][j] == BLACK) continue;
			// 비어 있거나 검정 블록인 경우 continue

			// 현재행(i)의 다음행부터 탐색하여 EMPTY가 아닐 때까지 행간 블록 데이터 교환
			for (int k = i+1; k < N; k++) {
				if (board[k][j] == EMPTY) {
					// (k, j)가 빈 좌표인 경우
					board[k][j] = board[k-1][j]; // (k, j)에 (k-1, j)의 값 전달
					board[k-1][j] = EMPTY; // (k-1, j)는 EMPTY로 변경
				}
				else // (k, j) 가 빈 좌표가 아닌 경우
					break;
			}
		}

	}
}

void rotate90() {
	// 배열을 90도 회전 시킴
	vector<vector<int> > new_board = vector<vector<int> > (N, vector<int> (N,0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			new_board[i][j] = board[j][N-i-1]; 
		}
	}
	board = new_board;
}

int main() {
	// 입력
	cin >> N >> M; 
	board = vector<vector<int> > (N, vector<int>(N)); 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cin >> board[i][j]; 

	// 풀이
	while (find_largest_block_group()) {
		// 가장 큰 블록이 존재하는 동안 반복
		delete_best_block_group(); // 가장 큰 블록 제거 및 점수 획득
		work_gravity(); // 중력 작용
		rotate90(); // 90도 회전
		work_gravity(); // 중력 작용
	}

	cout << score << endl; 
}