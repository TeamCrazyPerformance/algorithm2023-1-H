#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std; 

int main()
{

	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 
	int n, m;
	cin >> n >> m;

	vector< pair<int, int> > cities[1001];
	int a, b, c;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		cities[a].push_back(make_pair(c, b)); 
	}

	int start, end; 
	cin >> start >> end; 

	//vector<int> previous[1001]; 
	long long int updated[1001] = {0}; 

	for (int i = 1; i <= n; i++) {
		updated[i] = INT_MAX; 
	}
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > >pq;

	// The pair: <거리, 노드>
	updated[start] = 0; 
	int previous[1001];

	previous[start] = INT_MAX;
	pq.push(make_pair(0, start)); 

	int dist, node;

	while(!pq.empty()) {
		dist = pq.top().first; 
		node = pq.top().second; 
		pq.pop(); 

		if (updated[node] == INT_MAX) continue; 
		// 업데이트가 될 것인가? 그렇다면 큐에 넣고 값 업데이트. 

		while (!cities[node].empty()) {

			if (updated[cities[node].back().second] > updated[node] + cities[node].back().first) {
				pq.push(make_pair(updated[node] + cities[node].back().first, cities[node].back().second));

				previous[cities[node].back().second] = node;
				
				updated[cities[node].back().second] = updated[node] + cities[node].back().first;
			}

			cities[node].pop_back(); 				
		}
		
	}

	vector<int> result;
	int val = end;
	do {
		result.push_back(val); 
		val = previous[val]; 
	} while (val != INT_MAX); 


	cout << updated[end] << "\n" << result.size() << "\n";


	for (int i = result.size()-1; i >= 0; i--) {
		cout << result[i] << " ";
	}

	cout << "\n"; 

}
