#include<bits/stdc++.h>

using namespace std;

class Tree{
public:
  int N;
  vector<vector<int>> adj;
  Tree() {
    cin >> N;
    this->adj = vector<vector<int>>(N+1, vector<int>());
    this->parents = vector<int> (N+1);

    int x, y;
    for(int i=0; i<N-1; i++) {
      cin >> x >> y;
      addEdge(x, y);
    }
  }
  void findParents(int node, int parent) {
    if(parent == 0) this->parents[node] = 0;
    else this->parents[node] = parent;
    for(auto cur: adj[node]) {
      if(cur != parent) findParents(cur, node);
    }
  }

  void printParents() {
    for(int i=2; i<N+1; i++) {
      cout << parents[i] << "\n";
    }
  }
private:
  vector<int> parents;

  void addEdge(int x, int y) {
    this->adj[x].push_back(y);
    this->adj[y].push_back(x);
  }
  
};

int main() {
  Tree tree;
  tree.findParents(1, 0);
  tree.printParents();
  return 0;
}
