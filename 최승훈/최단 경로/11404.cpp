#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 9999999

void floyd_warshall(vector<vector<int>>& Bus) {
    for (int i = 1; i <= Bus.size() - 1; i++)             // i거쳐서 j -> k
        for (int j = 1; j <= Bus.size() - 1; j++)         // j에서 출발
            for (int k = 1; k <= Bus.size() - 1; k++)     // k에서 도착
                if (Bus[j][i] != INF && Bus[i][k] != INF)
                    Bus[j][k] = min(Bus[j][k], Bus[j][i] + Bus[i][k]);
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;
    vector<int> v(vertex + 1, INF);
    vector<vector<int>> Bus(vertex + 1, v);
    
    // 가중치 값 넣기
    for (int i = 0; i < edge; i++) {    
        int from, to, weight;
        cin >> from >> to >> weight;
        if (Bus[from][to] > weight)
            Bus[from][to] = weight;
    }
    floyd_warshall(Bus);
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if (i == j || Bus[i][j] == INF)
                cout << 0 << " ";
            else
                cout << Bus[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
