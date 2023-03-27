#include <iostream>

using namespace std;

int tree[10001];
int i;

void postorder(int start, int end) {
	if (start >= end) 
		return;

	for (i = start + 1; i < end; i++)
		if (tree[start] < tree[i]) 
			break;

	postorder(start + 1, i);
	postorder(i, end);
	cout << tree[start] << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int x = 0, idx = 0;

	while (cin >> x) 
		tree[idx++] = x;
		
	postorder(0, idx);

	return 0;
}
