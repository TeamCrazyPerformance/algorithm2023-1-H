#include <iostream>
using namespace std; 

int parent[1000001] = {0};
int x, y; 

void initializeParent(int n) {
	for (int i = 0; i <= n; i++) parent[i] = i;
}

// root 노드를 찾는 과정.
int Find(int num) {
	if (parent[num] == num) return num; 

	parent[num] = Find(parent[num]);
	return parent[num]; 
}

void Union(int a, int b) {
	int x = Find(a); 
	int y = Find(b); 
	if (x <= y) parent[y] = x; // parent[b] = x; 가 아니라는 점 유의. 
	else parent[x] = y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; 
	cin >> n >> m; 

	initializeParent(n); 

	int findOrUnion, a, b; 
	for (int i = 0; i < m; i++) {
		cin >> findOrUnion >> a >> b;
		if (findOrUnion == 0) Union(a, b); 
		else {
			if(Find(a) == Find(b))cout << "YES\n"; 
			else cout << "NO\n";  
		}
	}
}