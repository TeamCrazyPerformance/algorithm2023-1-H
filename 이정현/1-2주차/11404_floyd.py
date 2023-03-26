import sys
input = sys.stdin.readline
INF = 1000000000

# Set the number of vertices and edges
v = int(input())
e = int(input())

# Set dist array with INF and 0 (when the target v from a vertice is itself)
dist = [[INF for _ in range(v)] for _ in range(v)]
for i in range(v):
    dist[i][i] = 0

# Get input
for i in range(e):
    start, end, cost = list(map(int, input().split()))
    dist[start-1][end-1] = min(dist[start-1][end-1], cost)

# Floyd
for k in range(v):
    for i in range(v):
        for j in range(v):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

# Print out
for i in dist:
    for j in i:
        if j == INF:
            print(0, end=" ")
        else:
            print(j, end=" ")
    print()
