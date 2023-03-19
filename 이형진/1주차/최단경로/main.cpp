#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

vector<pair<int, int> > nodes[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >
    pq;

int dists[20001];

void solve(int start) {
  pq.push(make_pair(0, start));
  dists[start] = 0;
  while (!pq.empty()) {
    int dist = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (int i = 0; i < nodes[node].size(); i++) {
      int n = nodes[node][i].first;
      int w = nodes[node][i].second;

      if (dist + w < dists[n]) {
        dists[n] = dist + w;
        pq.push(make_pair(dists[n], n));
      }
    }
  }
}

int main() {

  int V, E, K;
  cin >> V >> E;
  cin >> K;

  for (int i = 1; i <= V; i++) {
    dists[i] = INF;
  }

  int u, v, w;
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    nodes[u].push_back(make_pair(v, w));
  }

  solve(K);

  for (int i = 1; i <= V; i++) {
    if (dists[i] == INF) {
      cout << "INF\n";
    } else {
      cout << dists[i] << "\n";
    }
  }

  return 0;
}
