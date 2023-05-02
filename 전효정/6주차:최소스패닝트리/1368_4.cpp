#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int N;
int paddies[301];
int visited[301];
int parents[301];

// 가중치, (정점1, 정점2)
vector<pair<int, pair<int, int> > > mst;

void initialize() {
	for (int i = 0; i <= N; i++) {
		parents[i] = i;
	}
}

int Find(int num) {
	if (parents[num] == num) return num; 
	return parents[num] = Find(parents[num]); 
}

void Union(int a, int b) {
	int rootA = Find(a); 
	int rootB = Find(b); 

	if (paddies[rootA] < paddies[rootB]) parents[rootB] = parents[rootA];
	else parents[rootA] = parents[rootB];
}

int main()
{
	cin >> N; 
	initialize(); 
	int W; 
	for (int i = 1; i <= N; i++) {
		cin >> W; 
		paddies[i] = W;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> W;
			if (W == 0) continue;
			mst.push_back(make_pair(W, make_pair(i, j)));
		}
	}

	sort(mst.begin(), mst.end());


	long long int weight = 0; 

	int rootA, rootB;
	for (int i = 0; i < mst.size(); i++) { 

		if (visited[mst[i].second.first] == 1 &&
			visited[mst[i].second.second] == 1) continue;

		if (visited[mst[i].second.first] == 1 &&
			mst[i].first < mst[i].second.second) {
			weight += mst[i].first;

			Union(mst[i].second.second, mst[i].second.first);

			visited[mst[i].second.second] = 1;
		} 

		else if (visited[mst[i].second.second] == 1 &&
			mst[i].first < mst[i].second.first) {
			weight += mst[i].first;

			Union(mst[i].second.second, mst[i].second.first);

			visited[mst[i].second.first] = 1;
		}

		else if (mst[i].first < paddies[mst[i].second.first] || mst[i].first < paddies[mst[i].second.second]) {

			rootA = Find(mst[i].second.first); 
			rootB = Find(mst[i].second.second); 

			if (rootA == rootB) continue;

			weight += mst[i].first;

			Union(mst[i].second.second, mst[i].second.first);

			visited[mst[i].second.first] = 1;
			visited[mst[i].second.second] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (parents[i] == i) {
			weight += paddies[i];
		}
	}

	cout << weight;
}