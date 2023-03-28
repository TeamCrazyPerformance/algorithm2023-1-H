#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

void add_node(node* ptr, int data) {
	if (ptr != NULL) {
		if (data < ptr->data) {
			if (ptr->left != NULL) {
				add_node(ptr->left, data);
			}
			else {
				node* newnode = (node*)malloc(sizeof(node));
				newnode->left = NULL;
				newnode->right = NULL;
				newnode->data = data;
				ptr->left = newnode;
			}
		}
		else {
			if (ptr->right != NULL) {
				add_node(ptr->right, data);
			}
			else {
				node* newnode = (node*)malloc(sizeof(node));
				newnode->left = NULL;
				newnode->right = NULL;
				newnode->data = data;
				ptr->right = newnode;
			}
		}
	}
}
	
void postorder(node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}

int main() {
	node* root = (node*)malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	int a;
	scanf("%d", &a);
	root->data = a;
	while (scanf("%d", &a) != EOF) {
		add_node(root, a);
	}

	postorder(root);
	return 0;
}
