#include <iostream>
#include <vector>
using namespace std; 

int N, M;
int parents[201];

void initialize() {
	for (int i = 0; i <= N; i++) parents[i] = i; 
}

int Find(int num) {
	if (parents[num] == num) return num; 
	return parents[num] = Find(parents[num]); 
}

void Union(int a, int b) {
	int rootA = Find(a); 
	int rootB = Find(b);

	if (rootA < rootB) parents[rootB] = parents[rootA];
	else parents[rootA] = parents[rootB];  
}

int main() {
	
	cin >> N >> M; 
	vector<int> cities[201];
	int num;

	initialize(); 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num; 
			if (num == 1) Union(i, j); 
		}
	}

	// result.
	cin >> num; 
	int root = Find(num);
	int cmp;
	for (int i = 1; i < M; i++) {
		cin >> num;
		cmp = Find(num);
		if (root != cmp) {
			cout << "NO\n"; 
			return 0; 
		}
	}

	cout << "YES\n";
	return 0; 
}