#include<bits/stdc++.h>

using namespace std;

struct Node {
  char data;
  Node* left;
  Node* right;

  Node(char data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BinaryTree {
public:
  Node* root;

  BinaryTree() {
    root = new Node('A');
  }

  void addNode(vector<char> data) {
    Node* focusedNode = findNode(data[0], root);
    if(data[1] != '.') focusedNode->left = new Node(data[1]);
    if(data[2] != '.') focusedNode->right = new Node(data[2]);
  }

  Node* findNode(char key, Node* curNode) {
    if(curNode==nullptr) return nullptr;
    if(curNode->data == key) return curNode;
    Node* findedNode = findNode(key, curNode->left);
    if(findedNode == nullptr)
      return findNode(key, curNode->right);
    return findedNode;
  }

  void preOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
      std::cout << focusNode->data;
      preOrderTraversal(focusNode->left);
      preOrderTraversal(focusNode->right);
    }
  }
  void inOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
      inOrderTraversal(focusNode->left);
      std::cout << focusNode->data;
      inOrderTraversal(focusNode->right);
    }
  }
  void postOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
      postOrderTraversal(focusNode->left);
      postOrderTraversal(focusNode->right);
      std::cout << focusNode->data;
    }
  }
};

int main() {

  int N;
  BinaryTree bt;

  cin >> N;
  while(N--) {
    char a,b,c;
    cin >> a >> b >> c;
    bt.addNode(vector<char>{a,b,c});
  }

  bt.preOrderTraversal(bt.root);
  cout << "\n";
  bt.inOrderTraversal(bt.root);
  cout << "\n";
  bt.postOrderTraversal(bt.root);

  return 0;
}
