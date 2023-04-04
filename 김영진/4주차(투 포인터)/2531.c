#include<stdio.h>

int sushi_type[3001] = { 0 };
int sushi_table[30001] = { 0 };

int main() {
	int n, d, k, c;
	scanf("%d %d %d %d", &n, &d, &k, &c);
	for (int i = 1; i < n + 1; i++) {
		int tmp;
		scanf("%d", &tmp);
		sushi_table[i] = tmp;
	}
	int* start;
	int* end;
	int count = 0;
	start = end = sushi_table;
	start = start + 1;
	sushi_type[c]++;
	count++;
	for (int i = 0; i < k; i++) {
		end = end + 1;
		if (sushi_type[*end] == 0) {
			count++;
		}
		sushi_type[*end]++;
	}
	int max_count = count;
	for (int i = 0; i < n - k; i++) {
		if (sushi_type[*start] == 1) {
			count--;
		}
		sushi_type[*start]--;
		start = start + 1;
		
		end = end + 1;
		if (sushi_type[*end] == 0) {
			count++;
		}
		sushi_type[*end]++;

		if (count > max_count) {
			max_count = count;
		}
	}
	end = sushi_table;
	for (int i = 0; i < k - 1; i++) {
		if (sushi_type[*start] == 1) {
			count--;
		}
		sushi_type[*start]--;
		start = start + 1;

		end = end + 1;
		if (sushi_type[*end] == 0) {
			count++;
		}
		sushi_type[*end]++;

		if (count > max_count) {
			max_count = count;
		}
	}
	printf("%d", max_count);
	return 0;
}
