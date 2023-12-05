import sys

n=int(input())
m=int(input())

graph=[[] for _ in range(n+1)]

for _ in range(m):
    a,b=map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

visited=[0 for _ in range(n+1)]

cnt=1

def DFS(l,graph, visited):
    global cnt
    visited[l]=cnt
    for g in graph[l]:
        if visited[g]==0:
            cnt += 1
            DFS(g, graph, visited)


DFS(1, graph, visited)

print(cnt-1)