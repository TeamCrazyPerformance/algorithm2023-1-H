#include<iostream>
#include<vector>

#define MAX 501
#define INF 1e9 + 7
using namespace std;

int N, M;
long long dist[MAX];
vector<pair<pair<int, int>, int>> line;

void bellman()
{
    dist[1] = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < line.size(); j++)
        {
            int start = line[j].first.first;
            int end = line[j].first.second;
            int cost = line[j].second;

            // 점에 도착할 수 없으므로 continue
            if (dist[start] == INF) 
                continue;

            // dist[end]가 더 크다면 갱신
            if (dist[end] > dist[start] + cost) 
                dist[end] = dist[start] + cost;
        }
    }

    for (int i = 0; i < line.size(); i++)
    {
        int start = line[i].first.first;
        int end = line[i].first.second;
        int cost = line[i].second;

        // 시작점이 갱신되지 않았다면 
        if (dist[start] == INF) 
            continue;

        // 음수 간선 cycle이 있다면
        if (dist[end] > dist[start] + cost)
        {
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        // 도착할 수 있는 방법이 없다면
        if (dist[i] == INF) 
            cout << -1 << "\n";

        // 도착할 수 있는 방법이 있다면
        else 
            cout << dist[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) 
        dist[i] = INF;
    for (int i = 0; i < M; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        line.push_back(make_pair(make_pair(start, end), cost));
    }
    
    bellman();

    return 0;
}
