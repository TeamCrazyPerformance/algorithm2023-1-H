#include <iostream>
#include <vector>
using namespace std; 

int arr[4000001];

void arrToOne(int N){ 
	for (int i = 1; i <= N; arr[i++] = 1);
}

int main()
{
	int N; 
	cin >> N; 

	// N이 1일 때를 유의할 것. 
	if (N == 1) {
		cout << "0";
		return 0; 
	}

	vector<int> prime;
	arrToOne(N);

	// prime 에는 N까지의 숫자 중에서 소수인 아이들만 넣어둠. 
	for (int i = 2; i <= N; i++) {
		if (arr[i] == 0) continue;
		prime.push_back(i); 
		for (int j = 2; i * j <= N; j++) {
			arr[i*j] = 0;
		}
	}

	int left = 0, right = 0, sum = prime[left], count = 0;

	while (left <= right) {
		if (sum < N) {
			if (right == prime.size()-1) break;
			right++;
			sum += prime[right];
		} else if (sum > N) {
			sum -= prime[left];
			left++;
		} else {
			count++;
			sum -= prime[left]; 
			left++;
		}
	}

	cout << count; 
}