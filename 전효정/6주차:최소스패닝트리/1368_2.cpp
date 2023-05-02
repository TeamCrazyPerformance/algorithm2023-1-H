#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int paddies[301];
int parents[301];
int visited[301];
vector<int, pair<int, int> > mst; 
priority_queue<pair<int, int> > pq;

int Find(int num) {
	if (parents[num] == num) return num; 
	return parents[num] = Find(parents[num]); 
}

void Union(int a, int b) {
	int rootA = Find(a); 
	int rootB = Find(b); 

	if (rootA < rootB) parents[rootB] = parents[rootA];
	else parents[rootA] = parents[rootB]; 
}

int main()
{
	int N; 

	cin >> N; 

	int W, minVal = 100001, minIndex; 
	for (int i = 1; i <= N; i++) {
		cin >> W; 
		paddies[i] = W;
		if (W < minVal) {
			minVal = W; 
			minIndex = i; 
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> W; 
			if (W == 0) continue; 
			mst[i].push_back(make_pair(W, j));
			mst[j].push_back(make_pair(W, i));
		}
	}

	pq.push(make_pair(minVal, minIndex));

	int weight = minVal; 
	visited[minIndex] = 1;

	while (!pq.empty()) {
		for (int i = 0; i < mst[minIndex].size(); i++) {
			if (visited[mst[minIndex][i]] == 1) continue;
			
		}
		
	}

}