#include<bits/stdc++.h>

using namespace std;

class Tree{
public:
  int N;
  int R;
  int Q;
  vector<vector<int>> adj;
  Tree() {
    cin >> N >> R >> Q;
    this->adj = vector<vector<int>>(N+1, vector<int>());
    this->childNum = vector<int> (N+1, 0);
    this->visit = vector<int>(N+1, 0);

    int x, y;
    for(int i=0; i<N-1; i++) {
      cin >> x >> y;
      addEdge(x, y);
    }

    calChildrenNum(R);

    int a;
    for(int i=0; i<Q; i++) {
      cin >> a;
      cout << childNum[a] << "\n";
    }
  }

  int calChildrenNum(int root) {
    visit[root] = 1;
    int res = 1;
    for(int i=0; i<adj[root].size(); i++) {
      int next = adj[root][i];
      if(visit[next]) continue;
      res += calChildrenNum(next);
    }
    childNum[root] = res;
    return res;
  }
private:
  vector<int> childNum;
  vector<int> visit;

  void addEdge(int x, int y) {
    this->adj[x].push_back(y);
    this->adj[y].push_back(x);
  }
  
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  Tree tree;
  return 0;
}
