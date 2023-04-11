#include<stdio.h>

int arr[100001] = { 0 };

int main() {
	int left = 0;
	int right = 0;
	int count = 1;
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int tmp = arr[0];
	while (tmp < s) {
		right++;
		tmp += arr[right];
		count++;
		if (arr[right] == 0) {
			count = 0;
			break;
		}
	}
	int count_min = count;
	while (arr[right] != 0) {
		for (; tmp - arr[left] >= s;) {
			tmp -= arr[left];
			left++;
			count--;
		}
		if (count < count_min) {
			count_min = count;
		}
		right++;
		tmp += arr[right];
		count++;
	}
	printf("%d", count_min);
	return 0;
}
