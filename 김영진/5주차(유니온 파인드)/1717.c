#include<iostream>
using namespace std;

int parent[1000001];

int find(int n) {
	if (parent[n] == n) {
		return n;
	}
	else {
		return parent[n] = find(parent[n]);
	}
}

void merge(int a, int b) {
	if (find(a) != find(b)) {
		parent[find(b)] = find(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + 1; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> c >> a >> b;
		if (c) {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			merge(a, b);
		}
	}
	return 0;
}
