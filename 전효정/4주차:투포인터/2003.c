#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, sum = 0, result = 0;
	scanf("%d %d", &N, &M); 
	int *arr = malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) scanf("%d", arr+i);

	int *p1 = arr;
	int *p2 = arr;

	// p1 != NULL 을 넣으면 오류가 발생한다. 
	while (*p1 != '\0'){
		sum = 0;
		// p2 와 p1 은 동일한 포인터일까? -> 아닐 것이다.
		p2 = p1;
		while (1) {
			sum += *p2;
			if (sum > M || *p2 == '\0') break;
			if (sum == M) {
				result++;
				break;
			}
			p2++;
		}
		p1++;
	}

	printf("%d", result);
	free(arr);
}