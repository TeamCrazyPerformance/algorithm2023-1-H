#include <iostream>
#include <vector>
#include <limits.h>
using namespace std; 

int main()
{
	int N, S;
	cin >> N >> S;

	vector<int> v; 
	int num; 
	for (int i = 0; i < N; i++) {
		cin >> num; 
		v.push_back(num); 
	}

	int left = 0, right = 0;
	int count = 1, minCount = INT_MAX; 
	int sum = v[left];

	while (left <= right) {

		if (right == N) {
			sum -= v[left];
			if (sum >= S) {
				left++;
				count--;
				if (count < minCount) minCount = count; 
			} else {
				break;
			}
		} else if (sum >= S) {
			sum -= v[left];
			if (count < minCount) minCount = count; 
			count--;
			left++; 
		} else {
			right++;
			sum += v[right]; 
			count++; 
			if (left == 0) minCount = count; 
		}
	} 

	if (count > N && sum < S) cout << "0";
	else cout << minCount; 
}