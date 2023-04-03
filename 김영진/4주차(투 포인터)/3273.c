#include<stdio.h>

int a[2000000] = { 0 };

int main() {
	int n, x;
	int tmp;
	int count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		a[tmp]++;
	}
	scanf("%d", &x);
	for (int i = 1; i <= x/2; i++) {
		if (a[i] == 0) {
			continue;
		}
		else if (i != x - i) {
			count += a[i] * a[x - i];
		}
	}
	printf("%d", count);
	return 0;
}
