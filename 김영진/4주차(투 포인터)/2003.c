#include<stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, & m);
	int A[10001];
	A[0] = A[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	int* front;
	int* rear;
	front = rear = A;
	int sum = 0, count = 0;
	for (int i = 0; i < n; i++) {
		sum -= *front;
		front = front + 1;
		if (sum == m) {
			count += 1;
		}
		else {
			while (sum < m) {
				rear = rear + 1;
				sum += *rear;
			}
			while (sum > m) {
				sum -= *rear;
				rear = rear - 1;
			}
			if (sum == m) {
				count += 1;
			}
		}
	}

	printf("%d", count);
	return 0;
}
