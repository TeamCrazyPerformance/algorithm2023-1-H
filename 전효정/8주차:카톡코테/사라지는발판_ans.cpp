// 박진한
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std; 

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

enum Player {A, B};

pii DFS(vvi& board, Player p1, int x1, int y1, int x2, int y2) {
	Player p2 = p1 == A ? B : A;
	pii ret{ p2, 0};
	if (board[x1][y1]) for (int d = 0; d < 4; d++) {
		const int nx = x1 + "1012"[d] - '1';
		const int ny = y1 + "2101"[d] - '1';
		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) continue;
		board[x1][y1] = 0;
		auto [win, cnt] = DFS(board, p2, x2, y2, nx, ny);
		board[x1][y1] = 1; 
		if (win == p1) {
			if (ret.first == p1) ret.second = min(ret.second, cnt + 1); 
			else ret = { win, cnt + 1};
		}
		else if (ret.first == p2) ret.second = max(ret.second, cnt + 1);
	}
	return ret; 
}

int solution(vvi board, vi aloc, vi bloc) {
	const int ax = bloc[0], ay = aloc[1];
	const int bx = bloc[0], by = bloc[1];
	return DFS(board, A, ax, ay, bx, by).second;
}