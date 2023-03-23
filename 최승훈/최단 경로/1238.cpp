#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M, X;
const int INF = 1e9 + 7; //2 ^ 30에 근사하는 값 중 소수
vector<pii> graph[2][1001];
vector<int> dist[2];

void dijstra(int k) {
    dist[k][X] = 0;

    priority_queue <pii, vector<pii>, greater<pii>> q;
    q.push({ 0, X });

    while (!q.empty()) {
        int min_cost = q.top().first; // 도착 노드까지 최소 비용
        int now = q.top().second; // 도착 노드
        q.pop();

        // min_cost가 더 크면 갱신할 필요가 없으므로 continue
        if (min_cost > dist[k][now]) 
            continue;

        for (int i = 0; i < graph[k][now].size(); i++) {
            int next = graph[k][now][i].second;
            int next_cost = min_cost + graph[k][now][i].first;

            // next_cost가 더 작으면 갱신하고 방문하기 위해 Queue에 넣어줌
            if (next_cost < dist[k][next]) {
                dist[k][next] = next_cost;
                q.push({ next_cost, next });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int u, v, t;
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> t;
        graph[0][u].push_back(make_pair(t, v));
        graph[1][v].push_back(make_pair(t, u));
    }
    dist[0].resize(N + 1, INF);
    dist[1].resize(N + 1, INF);

    // 정점들 -> X 최단거리
    dijstra(1);

    // X -> 정점들 최단거리
    dijstra(0);

    int result = 0;
    for (int i = 1; i <= N; i++) 
        result = max(result, dist[0][i] + dist[1][i]);

    cout << result;

    return 0;
}
