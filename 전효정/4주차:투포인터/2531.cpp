#include <iostream>
#include <vector>
using namespace std; 

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

	int count = 0; 
	int max = 0; 
	int start = 0, end = 1; 

	int visited[3001] = {0};

	while (start < sushi.size()) {

		cout << "start: " << start << "end: " << end << endl;

		if (end >= sushi.size()) end = 0;

		if (end > start && end - start + 1 >= k || start > end && N - start + end + 1 >= k) {
			start++;
			end++;
			continue;
		}
	
		if (visited[sushi[end]] != 0 || sushi[end] == c) {
			--visited[sushi[start++]];
			continue;
		}

		++visited[sushi[start]];
		++visited[sushi[end++]];

		if (start > end && N - start + end + 1 > max) { 
			max = N - start + end + 1;
		}	
		if (end > start && end - start + 1 > max) {
			max = end - start + 1; 
		}

	}

	cout << max; 
}
