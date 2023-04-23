#include <iostream>
using namespace std;

int parents[500001]; 

int Find(int num) {
	if (parents[num] == num) return num; 
	return parents[num] = Find(parents[num]); 
} 

void Union(int a, int b) {
	int rootA = Find(a); 
	int rootB = Find(b); 

	if (rootA < rootB) parents[rootB] = rootA;
	else parents[rootA] = parents[rootB]; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; 
	cin >> n >> m; 
	// initialize
	for (int i = 0; i < n; i++) parents[i] = i; 

	int a, b;
	int rootA, rootB;  
	int result = 0; 

	int flag = 1; 
	for (int i = 1; i <= m; i++) {
		cin >> a >> b; 
		rootA = Find(a); 
		rootB = Find(b); 

		if (flag && rootA == rootB) {// 입력된 a와 b가 이미 같은 집합에 소속되어 있고, 
			// 이번 입력을 통해 a 와 b 가 연결되려 한다면.
			// 사이클 완성. 
			result = i;
			flag = 0; 
		}
		Union(a, b); 
	}
	cout << result; 
}