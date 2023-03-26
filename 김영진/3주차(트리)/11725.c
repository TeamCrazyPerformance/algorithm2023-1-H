#include<stdio.h>
#include<stdlib.h>

int arr[100001]; // arr[i]에는 연결된 노드의 개수를 저장
int brr[100001]; // brr[i]에는 부모 노드를 저장

typedef struct node {
	int data;
	struct node* next;
}node;

node* Arr[100001];

void find(int n) {
	node* cur;

	cur = Arr[n];

	for (int i = 0; i < arr[n]; i++) {
		cur = cur->next;
		if (brr[cur->data] == 0) {
			brr[cur->data] = n;
			find(cur->data);
		}
	}
	return;
}

int main() {
	int n;
	int x, y;
	int count = 0;
	node* cur;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		Arr[i + 1] = (node*)malloc(sizeof(node));
		Arr[i + 1]->next = NULL;
	}

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &x, &y);

		arr[x]++;
		cur = Arr[x];
		for (int j = 0; j < arr[x] - 1; j++) {
			cur = cur->next;
		}
		cur->next = (node*)malloc(sizeof(node));
		cur->next->data = y;
		cur->next->next = NULL;

		arr[y]++;
		cur = Arr[y];
		for (int j = 0; j < arr[y] - 1; j++) {
			cur = cur->next;
		}
		cur->next = (node*)malloc(sizeof(node));
		cur->next->data = x;
		cur->next->next = NULL;
	}

	find(1);

	for (int i = 2; i <= n; i++) {
		printf("%d\n", brr[i]);
	}

	return 0;
}
