#include <iostream>
#include <vector>
using namespace std; 

int paddies[301]; 
int path[301][301]; 
vector<int> visitedPaddy;
int visited[301]; 

int main()
{
	int N; 
	cin >> N; 

	int W; 


	int minVal = 100001; 
	int minIndex;
	for (int i = 1; i <= N; i++) {
		cin >> W; 
		paddies[i] = W; 
		if (minVal >= W) {
			minVal = W; 
			minIndex = i; 
		}
	}	


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> W; 
			if (W == 0) continue; 
			path[i][j] = W; 
		}
	}

	visitedPaddy.push_back(minIndex); 
	visited[minIndex] = 1; 
	int weight = minVal;

	while (visitedPaddy.size() != N) {
		for (int i = 0; i < visitedPaddy.size(); i++) {
			for (int j = 1; j <= N; j++) {
				if (j == visitedPaddy[i]) continue;

				if (visited[j] == 0 && path[visitedPaddy[i]][j] != 0 
					&& minVal >= path[visitedPaddy[i]][j]) {
					minVal = path[visitedPaddy[i]][j]; 
					minIndex = j;
				} 
			}
		}

		visitedPaddy.push_back(minIndex);
		if (minVal < paddies[minIndex]) weight += minVal;
		else weight += paddies[minIndex];
		visited[minIndex] = 1;

	}

	cout << weight;
}