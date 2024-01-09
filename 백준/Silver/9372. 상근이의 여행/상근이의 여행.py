import sys
sys.setrecursionlimit(10 ** 9)


def DFS(n, visited):
    global cnt
    if 0 not in visited[1:]:
        return
    else:
        for t in tree[n]:
            if visited[t] == 0:
                cnt += 1
                visited[t]=1
                DFS(t, visited)



T=int(input())
for _ in range(T):
    N,M=map(int, sys.stdin.readline().split())
    tree = [[] for _ in range(N+1)]
    for _ in range(M):
        a,b=map(int, sys.stdin.readline().split())
        tree[a].append(b)
        tree[b].append(a)
    visited=[0 for _ in range(N+1)]
    visited[1] = 1
    cnt=0
    DFS(1,visited)
    print(cnt)

