#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

vector<pair<int, int> > coor; 
vector<pair<double, pair<int, int> > > mst;

int n; 
int parents[1001];
int hasPath[1001][1001];

void initialize() {
	for (int i = 0; i <= n; i++) {
		parents[i] = i; 
	}
}

double distance(int i, int j) {
	return sqrt(pow(coor[i].first - coor[j].first, 2) + pow(coor[i].second - coor[j].second, 2)); 
}

int Find(int num) {
	if (parents[num] == num) return num; 
	return parents[num] = Find(parents[num]); 
}

int main()
{
	cin >> n; 

	initialize(); 
	coor.push_back(make_pair(0, 0));

	double x, y; 
	for (int i = 0; i < n; i++) {
		cin >> x >> y; 
		coor.push_back(make_pair(x, y)); 
	}

	double dist;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || hasPath[i][j] == 1) continue;
			hasPath[i][j] = 1; 
			hasPath[j][i] = 1; 
			dist = distance(i, j);
			mst.push_back(make_pair(dist, make_pair(i, j))); 
		}
	}

	sort(mst.begin(), mst.end()); 

	int rootA, rootB;

	double weight = 0; 
	for (int i = 0; i < mst.size(); i++) {
		rootA = Find(mst[i].second.first); 
		rootB = Find(mst[i].second.second); 

		if (rootA == rootB) continue;
		weight += mst[i].first; 

		if (rootA < rootB) parents[rootB] = parents[rootA]; 
		else parents[rootA] = parents[rootB]; 
	}

	printf("%.2lf\n", weight);
}