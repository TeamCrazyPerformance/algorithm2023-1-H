#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

void calEachNumberOfSubtree(vector<int> *tree, int *floor,
	vector<int> *priority, int *numberOfSubtrees, int max) {

	int current; 

	// priority 크기.
	for (int i = max; i >= 1; i--) {
		// 하나의 priority 벡터 요소에 대하여. 
		for(int k = 0; k < priority[i].size(); k++) {
			// 트리 돌기. 
			current = priority[i][k];
			numberOfSubtrees[current] = 1;
			for (int j = 0; j < tree[current].size(); j++) {
				if (numberOfSubtrees[tree[current][j]] == 0) numberOfSubtrees[tree[current][j]] = 1;

				if (floor[current] > floor[tree[current][j]]) {
					continue;
				}

				else numberOfSubtrees[current] += numberOfSubtrees[tree[current][j]];
			}
		}
	}
}

int main()
{
	// ios:sync 를 해줘야 시간초과가 안남. 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, Q; 
	cin >> N >> R >> Q; 
	vector<int> tree[100001];

	int U, V; 

	for (int i = 0; i < N-1; i++) {
		cin >> U >> V; 
		tree[U].push_back(V); 
		tree[V].push_back(U); 
	}

	int floor[100001] = {0}; 
	int visited[100001] = {0}; 

	// floor 계산하기. 
	queue<int> que; 
	vector<int> priority[100001];

	floor[R] = 1;
	visited[R] = 1;
	priority[1].push_back(R);  

	que.push(R); 
	int top, in; 

	int max = 0; 
	while (!que.empty()) {
		top = que.front(); 

		for (int i = 0; i < tree[top].size(); i++) {
			in = tree[top][i]; 
			if (visited[in] == 1) continue; 
			visited[in] = 1;

			que.push(in); 
			floor[in] = floor[top] + 1; 
			if (floor[in] > max) max = floor[in]; 
			priority[floor[in]].push_back(in);
		}
		que.pop(); 
	}

	int numberOfSubtrees[100001] = {0}; 
	calEachNumberOfSubtree(tree, floor, priority, numberOfSubtrees, max);
	for (int i = 0; i < Q; i++) {
		cin >> U; 
		cout << numberOfSubtrees[U] << "\n";
	}
}