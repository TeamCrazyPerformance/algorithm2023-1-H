#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std; 

int main()
{
	int N; 
	cin >> N; 
	vector<int> solution; 

	int num; 
	for (int i = 0; i < N; i++) {
		cin >> num; 
		solution.push_back(num); 
	}

	sort(solution.begin(), solution.end()); 

	int left, right;
	long long int currSum, minSum = LLONG_MAX;

	int minLeft, minRight, minI;

	for (int i = 0; i < N - 2; i++) {
		left = i + 1;
		right = N - 1;
		currSum = solution[i]; 
		while (left < right) {
			currSum += solution[left] + solution[right]; 
			if (abs(minSum) > abs(currSum)) {
				minSum = currSum;
				minI = i;
				minLeft = left; 
				minRight = right; 
			}
			if (currSum > 0) {
				right--;
			} else {
				left++;
			}
			currSum = solution[i]; 
		}
	}

	cout << solution[minI] << " " << solution[minLeft] << " " << solution[minRight];

}