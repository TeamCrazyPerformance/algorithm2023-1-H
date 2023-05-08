import sys
input = sys.stdin.readline

def find(parents, x):
    if parents[x] != x:
        parents[x] = find(parents, parents[x])
    return parents[x]

def union(parents, a, b):
    a = find(parents, a)
    b = find(parents, b)
    if a < b:
        parents[b] = a
    else:
        parents[a] = b

V, E = list(map(int, input().split()))
edges = [list(map(int, input().split())) for _ in range(E)]
edges.sort(key=lambda x: x[2])

result = 0
cnt = 0
ps = [i for i in range(V+1)]

for i in range(E):
    if find(ps, edges[i][0]) == find(ps, edges[i][1]):
        continue

    union(ps, edges[i][0], edges[i][1])
    result += edges[i][2]
    cnt += 1

    if cnt == V-1:
        break

print(result)
