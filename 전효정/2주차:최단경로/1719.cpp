#include <iostream>
#include <limits.h>
using namespace std; 

int main()
{
	int vertex[201][201] = {0}; 
	int firstVisit[201][201] = {0}; 

	int n, m;
	cin >> n >> m; 

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) vertex[i][j] = 0; 
			else vertex[i][j] = INT_MAX;
		}
	}

	int start, end, time; 

	for (int i = 0; i < m; i++) {
		cin >> start >> end >> time; 
		vertex[start][end] = time; 
		vertex[end][start] = time; 
		firstVisit[start][end] = end;
		firstVisit[end][start] = start; 
	}

	// Floyed-Warshall
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == k || j == k) continue;
				if (vertex[i][k] == INT_MAX || vertex[k][j] == INT_MAX)
					continue;
				if (vertex[i][j] > vertex[i][k] + vertex[k][j]) {
					vertex[i][j] = vertex[i][k] + vertex[k][j]; 

					firstVisit[i][j] = firstVisit[i][k]; 
				} 
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << firstVisit[i][j] << " "; 
		}
		cout << "\n"; 
	}

}