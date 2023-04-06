#include<stdio.h>
#include<stdlib.h>

int arr[100000] = { 0 };

int compare(int* x, int* y) {
	if (*x > *y) {
		return 1;
	}
	else if (*x < *y) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[i] = tmp;
	}
	qsort(arr, n, sizeof(int), compare);
	int* OH;
	int* H;
	OH = arr;
	H = arr + n - 1;
	int max = 2000000000;
	int min = -2000000000;
	int a, b, c, d;
	while (*OH != *H) {
		if (0 < *OH + *H && *OH + *H < max) {
			max = *OH + *H;
			a = *OH;
			b = *H;
		}
		else if (0 > *OH + *H && *OH + *H > min) {
			min = *OH + *H;
			c = *OH;
			d = *H;
		}
		if (*OH + *H < 0) {
			OH = OH + 1;
		}
		else if (*OH + *H > 0) {
			H = H - 1;
		}
		else {	// *OH + *H == 0
			break;
		}
	}
	if (*OH + *H == 0) {
		printf("%d %d", *OH, *H);
	}
	else if (-min < max) {
		printf("%d %d", c, d);
	}
	else {	// -min > max
		printf("%d %d", a, b);
	}
	return 0;
}
