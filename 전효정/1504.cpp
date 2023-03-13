#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	int N, E; 
	cin >> N >> E; 

	int vertex[801][801];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) { 
			if (i == j) vertex[i][j] = 0; 
			else vertex[i][j] = INT_MAX;
		}
	}

	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		vertex[a][b] = c;
		vertex[b][a] = c; 
	}

	// Floyd-Warshall 
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (vertex[i][k] != INT_MAX && vertex[k][j] != INT_MAX) {
					vertex[i][j] = min(vertex[i][k] + vertex[k][j],
					vertex[i][j]); 
				}
			}
		}
	}

	int u, v; 
	cin >> u >> v;  
	
	int result; 

	if ( (vertex[1][u] != INT_MAX && vertex[u][v] != INT_MAX && vertex[v][N] != INT_MAX)
		&& (vertex[1][v] != INT_MAX && vertex[v][u] != INT_MAX && vertex[u][N] != INT_MAX)) {
		result = min(vertex[1][u] + vertex[u][v] + vertex[v][N],
		vertex[1][v] + vertex[v][u] + vertex[u][N]); 
	} else if ( (vertex[1][u] == INT_MAX || vertex[u][v] == INT_MAX || vertex[v][N] == INT_MAX) &&
		(vertex[1][v] != INT_MAX && vertex[v][u] != INT_MAX && vertex[u][N] != INT_MAX)) {
		result = vertex[1][v] + vertex[v][u] + vertex[u][N];
	} else if ( (vertex[1][u] != INT_MAX && vertex[u][v] != INT_MAX && vertex[v][N] != INT_MAX) &&
		(vertex[1][v] == INT_MAX || vertex[v][u] || INT_MAX && vertex[u][N] || INT_MAX)) {
		result = vertex[1][u] + vertex[u][v] + vertex[v][N];
	} else {
		result = -1; 
	}

	cout << result; 

}