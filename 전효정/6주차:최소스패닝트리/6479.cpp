// Kruskal Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 가중치, (정점1, 정점2)
vector<pair<long long int, pair<int, int> > > mst;
int parents[200001]; 
int m, n;

void initialize() {
	while (!mst.empty()) mst.pop_back(); 
	for (int i = 0; i <= n; i++) {
		parents[i] = i; 
	}
}

int Find(int num) {
	if (parents[num] == num) return num; 
	return parents[num] = Find(parents[num]); 
}

int kruskal() {
	int rootA, rootB;
	long long int weight = 0;
	for (int i = 0; i < n; i++) {
		rootA = Find(mst[i].second.first);
		rootB = Find(mst[i].second.second); 

		if (rootA == rootB) {
			weight += mst[i].first;
			continue;
		}

		if (rootA < rootB) parents[rootB] = parents[rootA]; 
		else parents[rootA] = parents[rootB]; 
	}

	return weight;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int x, y, z;
	while (1) { 
		cin >> m >> n; 

		if (m == 0 && n == 0) break;
		initialize();

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z; 
			mst.push_back(make_pair(z, make_pair(x, y))); 
		}

		sort(mst.begin(), mst.end());
		cout << kruskal(); 
	}
}