#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& D)
{
    // 시작 노드부터 어떤 도착 노드까지의 최소 비용을 제시하는 간선 목록
    D[start] = 0;
    // pair<-비용, 도착 노드> 
    priority_queue<pair<int, int> > pq;
    // 시작 노드에서 도착 노드로 가는 비용와 경로을 pq에 저장 
    pq.push(make_pair(0, start));

    // pq 의 모든 경로들을 확인할 때까지 반복
    while (!pq.empty()) {
        // 가중치 음수로 저장 -> 가중치가 가장 작은 값이 top에 위치
        // 도착 노드를 현재 노드로 설정한다.
        int current = pq.top().second;
        // 시작 노드에서 현재 노드까지의 비용을 설정한다.
        // 비용은 양수로 바꿔서 사용한다.
        int weight = -pq.top().first;
        pq.pop();

        // top: 시작 노드부터 현재 노드까지의 비용, D[], 비교
        // top > D[n] 해당 경로를 통한 경로는 모두 top > D[n] -> 확인 x
        if (D[current] < weight) 
            continue;

        // if에 해당하지 않으면 현재 노드와 연결된 노드들을 모두 검사
        for (int i = 0; i < graph[current].size(); i++) {

            // 현재 노드와 i 번째로 인접한 노드
            int next = graph[current][i].second;

            // 시작 노드에서 현재 노드까지의 비용 + 현재 노드에서 i 번째로 인접한 노드까지의 비용
            int via = weight + graph[current][i].first;

            // 비용이 더 작다면 최소 비용 업데이트
            if (D[next] > via) {
                D[next] = via;
                pq.push(make_pair(-via, next));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
    }

    vector<int> D(V + 1, 1000000);
    dijkstra(K, graph, D);
    for (int i = 1; i < V + 1; ++i) {
        if (D[i] == 1000000)
            cout << "INF" << "\n";
        else 
            cout << D[i] << "\n";
    }
    return 0;
}
