#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>  // 왜 tuple 컴파일 안됨...?
using namespace std;

int main() 
{
	int N, M; 
	cin >> N >> M;

	int A, B, C;

	long long int updated[501] = {0}; 
	for (int i = 1; i <= N; i++) {
		updated[i] = INT_MAX; 
	}

	vector<int> busesA;vector<int> busesB;vector<int> busesC;

	int visitedOne = 0; 
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		if (A == 1) visitedOne = 1;
		busesA.push_back(A); busesB.push_back(B); busesC.push_back(C); 
	}

	updated[1] = 0; 

	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < M; j++) {
			A = busesA[j];B = busesB[j];C = busesC[j];
			updated[B] = min(updated[B], updated[A] + C); 
		}
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < M; j++) {
			A = busesA[j];B = busesB[j]; C = busesC[j]; 
			if (visitedOne == 0) break;
			if (updated[B] > updated[A] + C) {
				cout << "-1";
				return 0; 
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (visitedOne == 0 || updated[i] == INT_MAX) cout << "-1\n";
		else cout << updated[i] << "\n"; 
	}

    return 0; 

}
