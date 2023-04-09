#include<bits/stdc++.h>
#define INF 987654321

using namespace std;

class Solve{

private:
  vector<vector<int>> edges;
  vector<long long> dists;
  int N, M;

public:
  Solve() {
    cin >> this->N >> this->M;

    this->dists = vector<long long>(this->N+1, INF);
    this->edges = vector<vector<int>>(this->M);

    int a,b,c;
    for(int i=0; i<M; i++) {
      cin >> a >> b >> c;
      this->edges[i] = vector {a,b,c};
    }
  }

  bool bellmanFord(int start) {
    this->dists[start] = 0;

    for(int i=0; i<this->N; i++) {
      for(int j=0; j<this->M; j++) {
        int from = this->edges[j][0];
        int to = this->edges[j][1];
        long long dist = this->edges[j][2];

        if(this->dists[from] != INF && this->dists[from] + dist < this->dists[to]) {
          if(i == N-1) return false;
          this->dists[to] = this->dists[from] + dist;
        }
      }
    }
    return true;
  }

  void print_dists() {
    bool isNINF = this->bellmanFord(1);
    if(isNINF) {
      for(int i=2; i<=N; i++) {
        if(dists[i] == INF ) cout << "-1\n";
        else cout << this->dists[i] << "\n";
      }
    } else {
      cout << "-1\n";
    }
  }



};

int main() {
  Solve s;
  s.print_dists();
  return 0;
}
