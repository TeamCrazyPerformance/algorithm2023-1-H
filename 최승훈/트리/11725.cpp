#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

int N;
int parent[MAX];
bool visited[MAX];
vector<int> V[MAX];

void DFS(int start) {
    visited[start] = true;
    for (int i = 0; i < V[start].size(); i++) 
    {
        int next = V[start][i];
        if (!visited[next]) 
        {
            parent[next] = start;
            DFS(next);
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);
        V[y].push_back(x);
    }

    DFS(1);

    for (int i = 2; i <= N; i++) 
        cout << parent[i] << "\n";
}
