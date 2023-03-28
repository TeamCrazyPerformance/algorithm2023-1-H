#include <iostream>
#include <vector>
using namespace std; 

void visitedToZero(int *visited) {
	for (int i = 1; i < 3001; visited[i++] = 0);
}

int main()
{
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> sushi;
	int num; 
	for (int i = 0; i < N; i++) {
		cin >> num; 
		sushi.push_back(num);
	}	

	int visited[3001] = {0}; 

	int count, max = 0, flag = 0;

	int t;
	for (int i = 0; i < N; i++) {
		count = 0; 
		flag = 0;
		visitedToZero(visited);
		t = i;
		for (int j = 0; j < k; j++) {
			if (t >= N) t = 0; 
			if (sushi[t] == c) {
				flag = 1;
			}
			if (visited[sushi[t]] == 0) {
				visited[sushi[t]] = 1; 
				count++; 
			}
			t++;
		}
		if (flag == 0) count++;
		if (count > max) max = count; 
	}

	cout << max; 
}