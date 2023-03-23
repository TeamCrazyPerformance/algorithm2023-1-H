#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int N; 
	cin >> N;
	
	vector<int> edges[100001];
	queue<int> que;
	int roots[100001] = {0};

	int a, b; 
	for (int i = 1; i <= N-1; i++) {
		cin >> a >> b;
		edges[a].push_back(b); 
		edges[b].push_back(a); 
	}

	que.push(1); 

	int pop;
	while (!que.empty()) {
		while (!edges[que.front()].empty()) {
			pop = que.front();
			que.push(edges[que.front()].back());
			edges[que.front()].pop_back();
			if (roots[que.back()] == 0) {
				roots[que.back()] = pop; 
			}
		}

		que.pop(); 
	}

	for (int i = 2; i <= N; i++) {
		cout << roots[i] << '\n';
	}
}