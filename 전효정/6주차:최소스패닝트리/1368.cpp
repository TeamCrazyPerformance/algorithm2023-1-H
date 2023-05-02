#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N; 
int paddies[301]; 
int visited[301]; 
vector<pair<int, int> > mst[301]; 
vector<int> visitedPaddy; 

int main()
{
	cin >> N; 

	int W; 
	int minVal = INT_MAX;
	int minPaddy;
	for (int i = 1; i <= N; i++) {
		cin >> W; 
		paddies[i] = W;
		if (minVal > W) {
			minVal = W; 
			minPaddy = i; 
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> W;
			if (W == 0) continue; 
			mst[i].push_back(make_pair(W, j));
			mst[j].push_back(make_pair(W, i));  
		}
	}

	long long int weight = minVal; 
	visitedPaddy.push_back(minPaddy);
	visited[minPaddy] = 1;

	while (visitedPaddy.size() != N) {
		minVal = INT_MAX;

		for (int j = 0; j < visitedPaddy.size(); j++) {
			for (int k = 0; k < mst[visitedPaddy[j]].size(); k++) {
				if (visited[mst[visitedPaddy[j]][k].second] == 1) {
					continue;
				}
				if (mst[visitedPaddy[j]][k].first < minVal) {
					minPaddy = mst[visitedPaddy[j]][k].second;
					minVal = mst[visitedPaddy[j]][k].first; 
				}	
			}
		}	

		if (minVal == INT_MAX) continue;

		if (paddies[minPaddy] < minVal) {
			weight += paddies[minPaddy]; 
		} else {
			weight += minVal;
		}

		visited[minPaddy] = 1;
		visitedPaddy.push_back(minPaddy);
	}
 
	cout << weight; 
}