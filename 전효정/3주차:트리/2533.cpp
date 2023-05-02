#include <iostream>
#include <vector>
#include <queue> 
using namespace std; 

// 배열 원소 백만 개 정도는 전역변수로 선언하면 됨. 
vector<int> tree[1000001];
int numberOfSubtrees[1000001] = {0};
int nodeOfParent[1000001] = {0}; 
int visited[1000001] = {0}; 
// pair: <서브 노드의 개수, 노드 번호>
priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;

int main()
{
	int N; 
	cin >> N; 

	int u, v;

	int maxIndex = 0; 
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		// u < v 이면 u 가 부모, v 가 자식.
		if (u < v) {
			tree[u].push_back(v);
			nodeOfParent[v] = u;
			numberOfSubtrees[u]++;
			if (u > maxIndex) {
				maxIndex = u; 
			}
		}
		else {
			tree[v].push_back(u);
			numberOfSubtrees[u] = v;
			numberOfSubtrees[v]++;
			if (v > maxIndex) {
				maxIndex = v; 
			}
		} 
	}

	for (int i = 1; i <= N; i++) {
		pq.push(make_pair(numberOfSubtrees[i], i));
	}

	int earlyAdaptor = 0;

	int first, second; 
	while (!pq.empty()) {
		if (visited[pq.top().second] == 1) {
			pq.pop(); 
			continue; 
		}
		if (numberOfSubtrees[pq.top().second] <= 0) pq.pop(); 
		else if (numberOfSubtrees[pq.top().second] != pq.top().first) {
			second = pq.top().second; 
			pq.pop(); 
			numberOfSubtrees[second]--;
			pq.push(make_pair(numberOfSubtrees[second], second));
		} else {
			earlyAdaptor++;
			second = pq.top().second; 
			cout << "node: " << second << " earlyAdaptor: " << earlyAdaptor << "\n";
			numberOfSubtrees[nodeOfParent[second]]--;
			visited[pq.top().second] = 1;
			pq.pop(); 
			for (int i = 0; i < tree[second].size(); i++) {
				if (visited[tree[second][i]] == 0) {
					visited[tree[second][i]] = 1;
					pq.push(make_pair(numberOfSubtrees[tree[second][i]], tree[second][i]));
				}
			}
		}
	}

	cout << earlyAdaptor;
	
	
}