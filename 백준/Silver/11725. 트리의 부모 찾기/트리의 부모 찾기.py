import sys
sys.setrecursionlimit(10**6)

N=int(input())
graph=[[] for _ in range(N+1)]
for _ in range(N-1):
    a,b=map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

parent=[None for _ in range(N+1)]
visited=[0 for _ in range(N+1)]
visited[1]=1
def DFS(n,parent, visited):
    for g in graph[n]:
        if visited[g]==0:
            parent[g]=n
            visited[g]=1
            DFS(g,parent, visited)

DFS(1,parent, visited)
for i in range(2,N+1):
    print(parent[i])