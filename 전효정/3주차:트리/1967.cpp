#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 
using namespace std; 

void makeVisitedToZero(int *visited, int n) {
	for (int i = 1; i <= n; visited[i++] = 0); 
}

int main()
{
	int n;
	int parent, child, w; 

	vector< pair<int, int> > tree[10001];

	cin >> n;

	for (int i = 0; i < n-1; i++) {
		cin >> parent >> child >> w; 
		tree[parent].push_back(make_pair(child, w));
		tree[child].push_back(make_pair(parent, w)); 
	}

	int visited[10001] = {0}; 
	queue< pair<int, int> > que; 

	// pair: <노드, 거리>
	int front, max = 0, cmp;
	for (int i = 1; i <= n; i++) {
		makeVisitedToZero(visited, n); 
		que.push(make_pair(i,0)); 

		while (!que.empty()) {
			front = que.front().first; 
			for (int j = 0; j < tree[front].size(); j++) {
				if (visited[tree[front][j].first] == 0) {
					que.push(make_pair(tree[front][j].first, tree[front][j].second));
					visited[tree[front][j].first] = visited[front] + que.back().second;
				}
			}
			que.pop(); 
		}

		cmp = *max_element(visited, visited + n);
		if (cmp > max) max = cmp; 

	}

	cout << max; 
}