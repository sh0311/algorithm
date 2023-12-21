import sys
sys.setrecursionlimit(10000)
T=int(input())


for _ in range(T):
    M, N, K = map(int, input().split())
    li = [[0 for _ in range(M)] for _ in range(N)]
    for _ in range(K):
        x, y = map(int, input().split())
        li[y][x] = 1

    visited = [[-1 for _ in range(M)] for _ in range(N)]


    def DFS(li, visited, i, j):
        dx = [1, -1, 0, 0]
        dy = [0, 0, -1, 1]
        for a in range(4):
            j2 = j + dx[a]
            i2 = i + dy[a]
            if i2 >= 0 and i2 < N:
                if j2 >= 0 and j2 < M:
                    if li[i2][j2] == 1 and visited[i2][j2] == -1:
                        visited[i2][j2] = 1
                        DFS(li, visited, i2, j2)


    num = 0
    for i in range(N):
        for j in range(M):
            if li[i][j] == 1 and visited[i][j] == -1:
                num += 1
                visited[i][j] = 1
                DFS(li, visited, i, j)

    print(num)