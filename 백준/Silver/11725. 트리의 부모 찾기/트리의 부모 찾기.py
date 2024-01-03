from collections import deque
import sys

N=int(sys.stdin.readline())
graph=[[] for _ in range(N+1)]
for _ in range(N-1):
    a,b=map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

parent=[0 for _ in range(N+1)]
visited=[False]*(N+1)

def BFS(visited, parent, n):
    deq=deque([n])
    visited[n]=True
    while deq:
        v = deq.popleft()
        for g in graph[v]:
            if not visited[g]:
                deq.append(g)
                visited[g]=True
                parent[g]=v

BFS(visited, parent, 1)
for i in range(2,N+1):
    print(parent[i])