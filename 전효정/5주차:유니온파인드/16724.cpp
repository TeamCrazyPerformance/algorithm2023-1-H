#include <iostream>
using namespace std;

int N, M;
int rootTable[1000001];
int isRoot[1001];

void initialize() {
	int num = 1; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			rootTable[(i-1) * M + j] = num++;
		}
	}
}  

int Find(int num) {
	if (rootTable[num] == num) return num; 
	return rootTable[num] = Find(rootTable[num]); 
}

void Union(int a, int b) {
	int rootA = Find(a); 
	int rootB = Find(b); 

	if (rootA < rootB) rootTable[rootB] = rootA;
	else rootTable[rootA] = rootB;
}

int main()
{ 
	cin >> N >> M; 

	initialize();	 

	string directions;
	char direction; 

	int cmp; 

	for (int row = 1; row <= N; row++) {
		cin >> directions;
		for (int col = 1; col <= M; col++) {
			direction = directions[col-1]; 

			cmp = rootTable[(row-1) * M + col];
			if (direction == 'U') {
				Union(cmp,rootTable[(row-2) * M + col]); 
			} else if (direction == 'D') {
				Union(cmp,rootTable[row * M + col]);
			} else if (direction == 'L') {
				Union(cmp,rootTable[(row-1) * M + (col-1)]);		
			} else if (direction == 'R') {
				Union(cmp,rootTable[(row-1) * M + (col+1)]);
			}
		}
	}

	// result. 
	// int root; 
	// for (int i = 1; i <= N; i++) {
	// 	for (int j = 1; j <= M; j++) {
	// 		root = Find(rootTable[(i-1) * M + j]);
	// 		isRoot[root] = 1; 
	// 	}
	// }



	int count = 0; 
	rootTable[1] = 1; 
	for (int i = 1; i <= N*M; i++) {
		if (rootTable[i] == i) count++; 
	}

	cout << count; 

}