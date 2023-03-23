#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct cmp{
	bool operator() (pair<int, int>&a, pair<int, int>&b) {
		return a.second > b.second; 
	}
};

void updatedToINF(int *updated, int N) {
	for (int i = 1; i <= N; i++) updated[i] = INT_MAX; 
} 

void visitedToZero(int *visited, int N) {
	for (int i = 1; i <= N; i++) visited[i] = 0; 
}

int dijkstra(priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > pq, 
	int visited[], int updated[], vector< pair<int, int> > villages[], int N) {
	
	int top; 
	while (!pq.empty()) {
		top = pq.top().first; 
		 
		pq.pop(); 

		for (int i = 0; i < villages[top].size(); i++) {
			
			if (updated[top] == INT_MAX) continue;
			if (villages[top][i].second + updated[top] < 
				updated[villages[top][i].first]) {
				updated[villages[top][i].first] =
					villages[top][i].second + updated[top];

				pq.push(make_pair(villages[top][i].first, 
					villages[top][i].second));
			}
		
		} 
	}
	
	return updated[N];
}


int main()
{
	int N, M, X;

	cin >> N >> M >> X;

	int a, b, T;
	vector< pair<int, int> > villages[1001];

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> T;
		villages[a].push_back(make_pair(b, T)); 
	}

	int visited[1001] = {0}; 
	int updated[1001] = {0}; 

	priority_queue< pair<int, int>, vector<pair<int, int> >, cmp > pq; 

	int largest = 0;
	int time;  
	for (int i = 1; i <= N; i++) {
		time = 0; 
		if (i == X) continue;
		updatedToINF(updated, N);
		visitedToZero(visited, N);
		while(!pq.empty()) pq.pop();
        
		// i 번째 노드에서 X 번째 노드로 갈 때.
		updated[i] = 0;
		pq.push(make_pair(i,0));
        time += dijkstra(pq, visited, updated, villages, X);

		updatedToINF(updated, N); 
		visitedToZero(visited, N);
		while(!pq.empty()) pq.pop();
        
        
		// X 번째 노드에서 i 번째 노드로 갈 때
		updated[X] = 0;
		pq.push(make_pair(X,0));
		time += dijkstra(pq, visited, updated, villages, i);


		if (time > largest) {
			largest = time; 
		}
	}

	cout << largest; 
}
