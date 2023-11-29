import sys
sys.setrecursionlimit(10 ** 6)
N,M,R=map(int, input().split())
graph=[[] for _ in range(N+1)]
for _ in range(M):
    a,b=map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1,N+1):
    graph[i].sort(reverse=True)

visited=[0 for _ in range(N+1)]
cnt=1

def dfs(graph, visited, R):
    global cnt
    visited[R]=cnt
    cnt += 1
    for j in graph[R]:
        if visited[j]==0:
            dfs(graph, visited, j)

dfs(graph, visited, R)

for i in range(1,N+1):
    print(visited[i])

