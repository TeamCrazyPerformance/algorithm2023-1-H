#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int parents[10001];
int V, E; 

void initialize() {
	for (int i = 0; i <= V; i++) {
		parents[i] = i; 
	}
}

int Find(int num) {
	if (parents[num] == num) return num; 
	return parents[num] = Find(parents[num]); 
}

int main()
{
	cin >> V >> E;

	// 거리의 가중치, (정점1, 정점2)
	vector<pair<int, pair<int, int> > > mst;  

	int A, B, C; 
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		mst.push_back(make_pair(C, make_pair(A, B)));  
	}

	sort(mst.begin(), mst.end()); 

	initialize(); 
	int rootA, rootB;
	long long int weight = 0;
	for (int i = 0; i < E; i++) {
		rootA = Find(mst[i].second.first);
		rootB = Find(mst[i].second.second); 

		if (rootA == rootB) continue;
		weight += mst[i].first;

		if (rootA < rootB) parents[rootA] = parents[rootB];
		else parents[rootB] = parents[rootA]; 
	}

	cout << weight; 
}