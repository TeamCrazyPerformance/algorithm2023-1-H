#include<bits/stdc++.h>
#define INF 987654321

using namespace std;

class Solve {
private:
  int n, m;
  vector<vector<int>> edges; 

public:
  Solve(int n, int m, vector<vector<int>> edges) {
    this->n = n;
    this->m = m;
    this->edges = edges;
  }
  
  vector<vector<int>> floydWarshall() {
    for(int k=1; k<=this->n; k++) {
      for(int i=1; i<=this->n; i++) {
        for(int j=1; j<=this->n; j++) {
          edges[i][j] = min(edges[i][j], edges[i][k]+edges[k][j]);
        }
      }
    }
    return this->edges;
  }

  void printDists() {
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        if(this->edges[i][j] == INF ) cout << "0 ";
        else cout << this->edges[i][j] << " ";
      }
      cout << "\n";
    }
  }

};

int main() {
  int n, m;
  vector<vector<int>> edges;

  cin >> n >> m;
  edges.resize(n+1, vector<int>(n+1, INF));
  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a][b] = min(edges[a][b], c);
  }
  for(int i=1; i<=n; i++) {
    edges[i][i] = 0;
  }

  Solve solve = Solve(n, m, edges);
  solve.floydWarshall();
  solve.printDists();

  return 0;
}
