import sys
sys.setrecursionlimit(10 ** 6)

N,M,R=map(int,input().split())

graph=[[] for _ in range(N+1)]
for _ in range(M):
    a,b=map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)
for j in range(N+1):
    graph[j].sort()



cnt=1

visited=[0]*(N+1)

def dfs(visited,graph,R):
    global cnt
    visited[R]=cnt
    for g in graph[R]:
        if visited[g]==0:
            cnt += 1
            dfs(visited,graph,g)

dfs(visited,graph,R)


for i in range(1,N+1):
    print(visited[i])