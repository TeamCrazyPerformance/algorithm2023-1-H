#include<iostream>
#include<vector>
#include<queue>

#define MAX 801
#define INF 1e9 + 7
using namespace std;

int N, E, A, B, result = INF;
int dist[MAX];
vector<pair<int, int>> V[MAX];

int min(int A, int B) 
{ 
    if (A < B) 
         return A; 
   return B; 
}

void dijkstra(int start)
{
    for (int i = 0; i <= N; i++) 
        dist[i] = INF;
    // 시작 노드부터 어떤 도착 노드까지의 최소 비용을 제시하는 간선 목록
    dist[start] = 0;
    // pair<-비용, 도착 노드> 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 시작 노드에서 도착 노드로 가는 비용와 경로을 pq에 저장 
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int current = pq.top().second;
        int cdist = pq.top().first;
        pq.pop();
        for (int i = 0; i < V[current].size(); i++) {
            int next = V[current][i].first;
            int ndist = V[current][i].second;
            if (dist[next] > cdist + ndist) {
                dist[next] = cdist + ndist;
                pq.push({ dist[next], next });
            }
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b, c; 
        cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }
    cin >> A >> B;
    
    bool flag1 = true, flag2 = true;

    // 1 -> A or B 가는 최소 비용   
    dijkstra(1);
    int stoA = dist[A];
    int stoB = dist[B];

    // A -> B 가는 최소 비용
    dijkstra(A);
    int AtoB = dist[B];
    // A -> N번 정점
    int AtoN = dist[N];

    // B -> N번 정점
    dijkstra(B);
    int BtoN = dist[N];

    result = min(result, stoA + AtoB + BtoN);
    result = min(result, stoB + AtoB + AtoN);
    
    if (AtoB == INF || result == INF) 
        cout << -1;
    else 
        cout << result;

    return 0;
}
