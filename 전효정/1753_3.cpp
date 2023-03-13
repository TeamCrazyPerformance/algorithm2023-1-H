#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;  // 이게 오름차순임. 
	}
};

int main() 
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 

	unsigned long long updated[20001] = {0};

	// updated 에 최댓값인 20,000을 넘는 값으로 초기화. 
	int V, E, K;
	cin >> V >> E >> K;

	for (int i = 1; i <= V; i++) {
		//updated[i] = 2000000;
		updated[i] = INT_MAX;
	}

	// updated[K], 즉 K 번째 정점은 시작점이므로 0 으로 업데이트. 
	updated[K] = 0;
	int u, v, w;

	vector< pair<int, int> > nodes[20001];

	// u 번째 정점에 연결된 v 정점과 두 정점을 연결하는 간선의 가중치 w. 
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		nodes[u].push_back(make_pair(w, v)); 
	}

	// 정점 v 와 가중치 w 를 쌍으로 묶어 담은 큐. 
	priority_queue< pair<int, int>, vector< pair<int, int> > > que;
		
	// 첫 번째 정점인 K와 가중치 0.
	que.push(make_pair(K, 0));
	int topV, topW;

	while (!que.empty()) {
		
		topV = que.top().second;
		que.pop();
		while (!nodes[topV].empty()) {
			que.push(make_pair(nodes[topV].back().second,
				nodes[topV].back().first));

			updated[nodes[topV].back().second] =
				min(updated[nodes[topV].back().second], 
				updated[topV] + nodes[topV].back().first);

			nodes[topV].pop_back(); 
        }
        
    }

	for (int i = 1; i <= V; i++) {
		if (updated[i] == INT_MAX) cout << "INF" << endl; 
		else cout << updated[i] << '\n'; 
	}

}
