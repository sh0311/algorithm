from collections import deque
import sys
sys.setrecursionlimit(10 ** 6)
N,M,R=map(int, input().split())

graph=[[] for _ in range(N+1)]

for _ in range(M):
    a,b=map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(N+1):
    graph[i].sort()

visited=[0 for _ in range(N+1)]

cnt=1
visited[R]=cnt


def bfs(graph, visited, R):
    global cnt
    deq=deque([R])
    visited[R]=cnt
    while deq:
        R = deq[0]
        deq.popleft()
        for g in graph[R]:
            if visited[g]==0:
                cnt+=1
                visited[g]=cnt
                deq.append(g)

bfs(graph, visited, R)

for i in range(1,N+1):
    print(visited[i])
