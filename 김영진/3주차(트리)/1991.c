#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
}node;

node* search(node* ptr, char p) {
	if (ptr != NULL) {
		if (ptr->data == p) {
			return ptr;
		}
		else {
			node* tmp = search(ptr->left, p);
			if (tmp != NULL) {
				return tmp;
			}
			else {
				return search(ptr->right, p);
			}
		}
	}
	else {
		return NULL;
	}
}

void add_child(node* root,char p, char l,char r) {
	node* ptr = root;
	ptr = search(ptr, p);
	if (l == '.') {

	}
	else {
		node* newnode_left = (node*)malloc(sizeof(node));
		newnode_left->left = NULL;
		newnode_left->right = NULL;
		newnode_left->data = l;
		ptr->left = newnode_left;
	}
	if (r == '.') {

	}
	else {
		node* newnode_right = (node*)malloc(sizeof(node));
		newnode_right->left = NULL;
		newnode_right->right = NULL;
		newnode_right->data = r;
		ptr->right = newnode_right;
	}
}

void preorder(node* root) {
	if (root != NULL) {
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

int main() {
	node* root = (node*)malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	root->data = 'A';

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char p, l, r;
		scanf(" %c %c %c", &p, &l, &r);
		add_child(root, p, l, r);
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);

	return 0;
}
