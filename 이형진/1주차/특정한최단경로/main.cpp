#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

class Solve {
private:
  int N, E;
  int v1, v2;
  vector<pair<int, int>> edges[200000];
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  vector<long> dists;

  void resetDists() {
    for(int i=1; i<=N; i++) {
      this->dists[i] = INF;
    }
  }

public:
  Solve() {
    cin >> this->N >> this->E;
    this -> dists.resize(N+1);
    resetDists();
   
    for(int i=1; i<=E; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      this->edges[a].push_back(make_pair(b,c));
      this->edges[b].push_back(make_pair(a,c));
    }

    cin >> v1 >> v2;
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
    long dist1, dist2, dist3;
    dijkstra(1);
    dist1 = dists[v1];
    resetDists();
    dijkstra(v1);
    dist2 = dists[v2];
    resetDists();
    dijkstra(v2);
    dist3 = dists[N];
    resetDists();
    
    if(dist1 != INF && dist2 != INF && dist3 != INF) return dist1+dist2+dist3;
    return -1;
  }

  long result() {
    int res1 = findRoot(v1, v2);
    int res2 = findRoot(v2, v1);
    return min(res1, res2);
  }
};

int main() {
  Solve solve;
  cout << solve.result();
  return 0;
}
