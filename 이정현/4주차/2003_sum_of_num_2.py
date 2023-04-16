import sys
input = sys.stdin.readline

n,m = list(map(int, input().split()))
arr = list(map(int, input().split()))
result = 0
l,h = 0,1

while True:
    if sum(arr[l:h]) == m:
        result += 1
        h += 1
    elif sum(arr[l:h]) > m:
        l += 1
    elif sum(arr[l:h]) < m:
        h += 1
    
    if h > n:
        break

print(result)
