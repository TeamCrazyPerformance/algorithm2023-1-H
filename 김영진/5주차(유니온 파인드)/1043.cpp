#include<iostream>
using namespace std;

int know_truth[51] = { 0 };
int listen_lie[51] = { 0 };
int parent[51];

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
	cin.tie(0), cout.tie(0);
	int ans = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	int truth, tmp;
	cin >> truth;
	for (int i = 0; i < truth; i++) {
		cin >> tmp;
		know_truth[tmp]++;
	}
	int check;
	int people[50];
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		check = 0;
		for (int j = 0; j < tmp; j++) {
			cin >> people[j];
			if (know_truth[people[j]]) {
				check++;
			}
			if (!find(people[j])) {
				check++;
			}
		}
		if (!check) {
			ans++;
			listen_lie[find(people[0])]++;
			for (int x = 1; x < tmp; x++) {
				if (listen_lie[find(people[x])]) {
					listen_lie[find(people[0])] += listen_lie[find(people[x])];
				}
				merge(people[0], people[x]);
			}
		}
		else {
			for (int x = 0; x < tmp; x++) {
				if (listen_lie[find(people[x])]) {
					ans -= listen_lie[find(people[x])];
				}
				merge(0, people[x]);
			}
		}
	}
	cout << ans;
	return 0;
}
