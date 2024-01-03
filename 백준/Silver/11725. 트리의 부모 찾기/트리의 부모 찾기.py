from collections import deque
N=int(input())
graph=[[] for _ in range(N+1)]
for _ in range(N-1):
    a,b=map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

parent=[None for _ in range(N+1)]
visited=[0 for _ in range(N+1)]

def BFS(visited, parent, n):
    deq=deque([n])
    visited[n]=1
    while deq:
        v = deq.popleft()
        for g in graph[v]:
            if visited[g] == 0:
                deq.append(g)
                visited[g]=1
                parent[g]=v

BFS(visited, parent, 1)
for i in range(2,N+1):
    print(parent[i])



