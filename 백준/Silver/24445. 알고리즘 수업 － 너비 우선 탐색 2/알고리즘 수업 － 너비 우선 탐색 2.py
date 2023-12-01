import sys
from collections import deque

N,M,R=map(int, sys.stdin.readline().split())

graph=[[] for _ in range(N+1)]
visited=[0 for _ in range(N+1)]

for _ in range(M):
    a,b=map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(N+1):
    graph[i].sort(reverse=True)

cnt=1

def bfs(visited, graph, R):
    global cnt
    visited[R]=cnt
    deq=deque([R])
    while deq:
        R=deq.popleft()
        for g in graph[R]:
            if visited[g]==0:
                cnt+=1
                visited[g]=cnt
                deq.append(g)

bfs(visited, graph,R)

for i in range(1,N+1):
    print(visited[i])