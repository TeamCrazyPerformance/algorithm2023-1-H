#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

int N, M;
vector<pair<int, int> > ships;

int visited[1001][1001];

// 가중치(거리), (정점1, 정점2)
vector<pair<long double, pair<int, int> > > mst; 
int parents[1001]; 

void initialize() {
	for (int i = 0; i <= N; i++) {
		parents[i] = i; 
	}
}

long double distance(int i, int j) {
	return sqrt(pow(ships[i].first - ships[j].first, 2) + pow(ships[i].second - ships[j].second, 2));
}

int Find(int num) {
	if (parents[num] == num) return num; 
	return parents[num] = Find(parents[num]); 
}

int main()
{ 
	cin >> N >> M; 
	initialize();

	int X, Y; 

	// ships의 첫 인덱스를 (0,0) 으로 채워 넣기 위함.
	ships.push_back(make_pair(0, 0)); 
	for (int i = 0; i < N; i++) {
		cin >> X >> Y; 
		ships.push_back(make_pair(X, Y)); 
	}

	for (int i = 0; i < M; i++) {
		cin >> X >> Y; 
		if (X < Y) parents[Y] = parents[X]; 
		else parents[X] = parents[Y]; 
	}

	long double dist;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || visited[i][j] == 1) continue;
			visited[i][j] = 1;
			visited[j][i] = 1; 
			dist = distance(i, j); 
			mst.push_back(make_pair(dist, make_pair(i, j))); 
		}
	}

	sort(mst.begin(), mst.end()); 

	int rootA, rootB; 
	long double weight = 0.0; 

	for (int i = 0; i < mst.size(); i++) {
		rootA = Find(mst[i].second.first); 
		rootB = Find(mst[i].second.second);
		if (rootA == rootB) continue;
		weight += mst[i].first; 
		if (rootA < rootB) parents[rootB] = parents[rootA]; 
		else parents[rootA] = parents[rootB]; 
	}

	printf("%.2Lf\n", weight);
}