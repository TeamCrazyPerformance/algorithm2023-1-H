#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n, m;
	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
		}
		cout << n - 1 << "\n";
	}
	return 0;
}
