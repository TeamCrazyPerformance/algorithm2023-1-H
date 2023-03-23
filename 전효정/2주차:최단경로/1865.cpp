#include <iostream>
#include <vector>
#include <limits.h>
using namespace std; 

void linksToZero(int links[][501], int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; links[i][j++] = 0);
	}
}

void updatedToINF(int updated[], int N) {
	for (int i = 1; i <= N; updated[i++] = 2047483647); 
}

void visitedToZero(int visited[], int N) {
	for (int i = 1; i <= N; visited[i++] = 0); 
}

bool TEST(vector< pair<int, int> > edge, int updated[], int links[][501]) {
	// TEST
	int S, E, T; 
	for (int i = 0; i < edge.size(); i++) {
		S = edge[i].first; 
		E = edge[i].second; 
		T = links[S][E]; 

		//if (updated[S] == INT_MAX) continue; 

		// 음수 cycle 이 있다는 뜻. -> 
		// 시간이 줄어들면서 출발 위치로 돌아오는 것이 가능한다는 뜻. 
		if (updated[E] > updated[S] + T) return true; 
	}
	return false;
}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC, N, M, W;
	cin >> TC;

	// https://www.acmicpc.net/board/view/50494
	// 그래프가 단절 되어 있을 경우... 이 알고리즘으로는 단절 되어 있는 '다른 사이클'에 대한
	// 음수 사이클을 확인할 수 없게 된다. 

	int links[501][501] = {0}; 
	int updated[501] = {0}; 

	int visited[501] = {0}; 
	// start, end
	vector< pair<int, int> > edge; 

	int S, E, T;
	while (TC--) {

		cin >> N >> M >> W;

		linksToZero(links, N); 
		updatedToINF(updated, N); 
		visitedToZero(visited, N); 
		while (!edge.empty()) edge.pop_back();

		int flag = 1, startNode = 1;

		// 이 코드는 시간초과를 발생시킴. 
		while (flag == 1) {
			flag = 0;
			// 도로
			for (int i = 0; i < M; i++) {
				cin >> S >> E >> T;
				edge.push_back(make_pair(S, E));
				edge.push_back(make_pair(E, S)); 
				if (links[S][E] != 0) links[S][E] = min(links[S][E], T); 
				else links[S][E] = T;
				if (links[E][S] != 0) links[S][E] = min(links[E][S], T); 
				else links[E][S] = T;
			}

			// 웜홀
			for (int i = 0; i < W; i++) {
				cin >> S >> E >> T; 
				edge.push_back(make_pair(S, E)); 
				if (links[S][E] != 0) links[S][E] = min(links[S][E], -T); 
				else links[S][E] = -T; 
			}

			updated[startNode] = 0;

			// Bellman-Ford
			for (int j = 0; j < N-1; j++) {
				for (int i = 0; i < edge.size(); i++) {
					S = edge[i].first; 
					E = edge[i].second; 
					T = links[S][E]; 

					//if (updated[S] == INT_MAX) continue; 

					visited[S] = 1; 
					updated[E] = min(updated[E], updated[S] + T); 
					visited[E] = 1; 
				}
			}

			// 방문이 안된 노드가 있다면.
			for (int i = 1; i <= N; i++) {
				if (visited[i] == 0) {
					flag = 1; 
					startNode = i; 
					break;
				}
			}
		}

		// TEST
		if (TEST(edge, updated, links)) cout << "YES\n"; 
		else cout << "NO\n"; 
		
	}
}