import sys
import heapq

V,E=map(int, sys.stdin.readline().split())
graph=[[]for _ in range(V+1)]
visited=[False for _ in range(V+1)]

for i in range(E):
    a,b,c=map(int, sys.stdin.readline().split())
    graph[a].append([c,b])
    graph[b].append([c,a])

cnt=0
heap=[[0,1]]


while heap:
    num,a=heapq.heappop(heap)
    if not visited[a]:
        visited[a]=True
        cnt+=num
        for g in graph[a]:
            if not visited[g[1]]:
                heapq.heappush(heap,g)


print(cnt)

