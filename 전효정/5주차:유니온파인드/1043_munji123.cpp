#include <iostream>
#include <vector>

using namespace std; 

vector<int> v[51]; 
bool ift[51]; 
int arr[51]; 
int n, m, t, tmp, cnt; 

int find(int x) {
	if (arr[x] == x) return x; 
	return arr[x] = find(arr[x]); 
}

void set_union(int x, int y) {
	x = find(x); 
	y = find(y); 
	if (x != y) {
		if (ift[x] || ift[y]) ift[x] = 1; 
		arr[y] = x; 
	}
}

int main()
{
	cin >> n >> m >> t; 
	for (int i = 1; i <= n; i++) arr[i] = i; 
	for (int i = 0; i < t; i++) {
		cin >> tmp; 
		ift[tmp] = 1;
	}
	for (int i = 0; i < m; i++) {
		int val = 0; 
		cin >> tmp; 
		for (int j = 0; j < tmp; j++) {
			cin >> val;
			v[i].push_back(val); 
		}

		int p = v[i][0]; 
		for (int j = 1; j < tmp; j++) {
			set_union(p, v[i][j]); 
		}
	}

	for (int i = 0; i < m; i++) {
		bool check = 1; 
		for (int j : v[i]) {
			if (ift[find(j)]) check = 0; 
		}
		if (check) cnt++; 
	}
}