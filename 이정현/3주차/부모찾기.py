import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())

tree = {i: [] for i in range(n+1)}
result = [0]*(n+1)
visited = [False]*(n+1)

def dfs(node):
    visited[node] = True
    for child in tree[node]:
        if not visited[child]:
            dfs(child)
            result[child] = node
    
for i in range(n-1):
    v1, v2 = list(map(int,input().split()))
    tree[v1].append(v2)
    tree[v2].append(v1)

dfs(1)

for i in result[2:]:
    print(i)
