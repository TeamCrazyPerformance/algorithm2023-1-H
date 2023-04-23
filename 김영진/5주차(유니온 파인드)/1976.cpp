#include<iostream>
using namespace std;

int city[201];

int find(int n) {
	if (city[n] == n) {
		return n;
	}
	else {
		return city[n] = find(city[n]);
	}
}

void merge(int a, int b) {
	if (find(a) != find(b)) {
		city[find(b)] = find(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		city[i] = i;
	}
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			if (i == j) {
				continue;
			}
			else {
				if (tmp) {
					merge(i, j);
				}
			}
		}
	}
	cin >> tmp;
	int root = find(tmp);
	for (int i = 0; i < m - 1; i++) {
		cin >> tmp;
		if (find(tmp) != root) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
