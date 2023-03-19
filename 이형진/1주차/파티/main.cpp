#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

class Solve {
private:
  int N, E, X;
  vector<pair<int, int>> edges[200000];
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  vector<long> dists;

  void resetDists() {
    for(int i=1; i<=N; i++) {
      this->dists[i] = INF;
    }
  }

  long max(vector<long> v) {
    long m = v[1];
    for(int i=2; i<v.size(); i++) {
      if(v[i] > m) m = v[i];
    }
    return m;
  }

public:
  Solve() {
    cin >> this->N >> this->E >> this -> X;
    this -> dists.resize(N+1);
    resetDists();
   
    for(int i=1; i<=E; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      this->edges[a].push_back(make_pair(b,c));
    }
  }

  void dijkstra(int start) {
    this->dists[start] = 0;
    this->pq.push(make_pair(0, start));

    while(!pq.empty()) {
      long cost = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for(int i=0; i<edges[node].size(); i++) {
        int n = edges[node][i].first;
        long w = edges[node][i].second;

        if(w + cost < dists[n]) {
          this->dists[n] = w+cost;
          this->pq.push(make_pair(dists[n], n));
        }
      }
    }
  }

  long findRoot(int v1, int v2) {
    int res = 0;
    dijkstra(v1);
    res += dists[v2];
    resetDists();
    dijkstra(v2);
    res += dists[v1];
    resetDists();
    return res;
  }

  long result() {
    vector<long> res(N+1, 0);
    for(int i=1; i<=N; i++) {
      res[i] = findRoot(i, X);
    }
    return max(res);
  }
};

int main() {
  Solve solve;
  cout << solve.result();
  return 0;
}
