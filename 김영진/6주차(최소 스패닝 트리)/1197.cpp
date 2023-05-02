#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int parent[10001] = { 0 };

int find(int n) {
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	if (find(a) != find(b)) {
		parent[find(b)] = find(a);
	}
}

struct edge {
	int a;
	int b;
};

bool compare(pair<int, edge> a, pair<int, edge> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int v, e;
	cin >> v >> e;
	for (int i = 1; i < v; i++) {
		parent[i] = i;
	}
	int a, b, c;
	int ans = 0;
	vector<pair<int, edge>> edge_case;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;	// a와b연결 가중치c
		edge* newedge = (edge*)malloc(sizeof(edge));
		newedge->a = a;
		newedge->b = b;
		edge_case.push_back(make_pair(c,*newedge));
	}
	sort(edge_case.begin(), edge_case.end(), compare);
	for (int i = 0; i < edge_case.size(); i++) {
		if (find(edge_case[i].second.a) != find(edge_case[i].second.b)) {
			merge(edge_case[i].second.a, edge_case[i].second.b);
			ans += edge_case[i].first;
		}
	}
	cout << ans;
	return 0;
}
