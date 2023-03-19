# 제일 작은 1이 시작점
import sys
import heapq

INF = 1000000

input = sys.stdin.readline

v, e = list(map(int, input().split()))  # node and edge
k = int(input())        # start node

data = [[] for _ in range(v+1)]
for _ in range(e):
    f, s, w = map(int, input().split())
    data[f].append((s,w))


heap = []       # minimum heap
dist = [INF]*(v+1)      # 가중치

def dijkstra(k):
    dist[k] = 0
    heapq.heappush(heap,(0,k))
    while heap:
        d, current = heapq.heappop(heap)
        for n,weight in data[current]:
            cost = d + weight
            if cost < dist[n]:
                dist[n] = cost
                heapq.heappush(heap,(cost,n))
        
dijkstra(k)

for i in dist[1:]:
    if i != INF:
        print(i)
    else:
        print("INF")
