#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std; 

int main()
{
	int N; 
	vector<pair<int, int> > solution; 

	cin >> N;

	// pair: <값, 음수/양수>
	int num; 
	for (int i = 0; i < N; i++) {
		cin >> num; 
		if (num < 0) solution.push_back(make_pair(-num, -1));
		else solution.push_back(make_pair(num, 1));
	}

	sort(solution.begin(), solution.end()); // 오름차순

	int minVal = INT_MAX;
	int val;

	int left, right;
	for (int i = 0; i < N-1; i++) {
		val = abs(solution[i].first * solution[i].second +
			solution[i+1].first * solution[i+1].second);
		if (val == 0) {
			left = i; right = i+1;
		}
		if (val < minVal) {
			minVal = val;
			left = i; right = i + 1;
		}
	}

	left = solution[left].first * solution[left].second;
	right = solution[right].first * solution[right].second;

	if (left < right) {
		cout << left << " " << right;
	} else {
		cout << right << " " << left; 
	}

	return 0;
}