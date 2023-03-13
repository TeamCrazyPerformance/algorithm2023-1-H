#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m; 

	long long int cities[101][101] = {0}; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cities[i][j] = 0;
			else cities[i][j] = 9223372036854675806;
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		// min 함수는 int 자료형만 지원하나봄...
		if (cities[a][b] > c) {
			cities[a][b] = c;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << cities[i][j] << " ";
		}
		cout << "\n"; 
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cities[i][k] == 9223372036854675806|| cities[k][j] == 9223372036854675806) continue;
				if (cities[i][j] > cities[i][k] + cities[k][j]) {
					cities[i][j] = cities[i][k] + cities[k][j]; 
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cities[i][j] == 9223372036854675806) cout << "0 ";
			else cout << cities[i][j] << " ";
		}
		cout << "\n"; 
	}
}
