#include <iostream>
#include <queue>
using namespace std;

void visitedToZero(int *visited, int n) {
	for (int i = 1; i <= n; visited[i++] = 0);
} 

void emptyTree(int tree[][501], int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			tree[i][j] = 0; 
	}
}

bool search(int tree[][501], int *visited, queue<int> que, int start, int n) {
	que.push(start); 
	visited[start] = 1; 

	bool trueOrFalse = true;
	int top; 
	while (!que.empty()) {
		top = que.front();
		
		for (int i = 1; i <= n; i++) {
			if (tree[top][i] == 1) {
				if (visited[i] == 1) trueOrFalse = false;
				que.push(i);
				visited[i] = 1; 
				tree[top][i] = 0; 
				tree[i][top] = 0; 
			}
			
		}

		que.pop(); 
	}

	return trueOrFalse; 
}

int main()
{
	int n, m;

	int from, to; 

	int tree[501][501] = {0}; 
	queue<int> que;
	int visited[501] = {0}; 

	int theNumberOfTrees; 

	int turn = 1; 
	while (turn) {
		cin >> n >> m;
		theNumberOfTrees = 0; 
		// 종료 조건. 
		while (!que.empty()) que.pop(); 
		if (n == 0 && m == 0) break; 
		
		for (int i = 0; i < m; i++) {
			cin >> from >> to;
			tree[from][to] = 1;
			tree[to][from] = 1; 
		} 

		int result; 
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) {
				result = search(tree, visited, que, i, n);
				if (result) {
					theNumberOfTrees++; 
				}
			}
		}

		cout << "Case " << turn << ": ";
		if (theNumberOfTrees == 0) {
			cout << "No trees.\n"; 
		} else if (theNumberOfTrees == 1) {
			cout << "There is one tree.\n";
		} else {
			cout << "A forest of " << theNumberOfTrees << " trees.\n";
		}

		visitedToZero(visited, n);
		emptyTree(tree, n); 

		turn++; 
	}

}