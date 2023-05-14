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

t = int(input())

for _ in range(t):
    cnt = 0
    n, m = list(map(int,input().split()))
    countries = [i for i in range(n+1)]

    for _ in range(m):
        a, b = list(map(int, input().split()))
        if find(countries, a) == find(countries, b):    # 서클이 있는지 확인
            continue
        union(countries, a,b)
        cnt += 1
    
    print(cnt)
