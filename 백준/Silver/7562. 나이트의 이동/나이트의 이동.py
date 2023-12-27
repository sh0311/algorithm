from collections import deque



def BFS(o_x,o_y):
    deq=deque([(o_x,o_y)])

    visited[o_y][o_x]=1
    while deq:
        dx = [1, 1, 2, 2, -1, -1, -2, -2]
        dy = [2, -2, 1, -1, 2, -2, 1, -1]
        n = deq.popleft()
        if n[0] == go_x and n[1] == go_y:
            return chess[n[1]][n[0]]
        for i in range(8):
            n_x = n[0] + dx[i]
            n_y = n[1] + dy[i]
            if n_x >= 0 and n_x < l:
                if n_y >= 0 and n_y < l:
                    if chess[n_y][n_x] == 0 and visited[n_y][n_x] == -1:
                        chess[n_y][n_x] = chess[n[1]][n[0]] + 1
                        deq.append((n_x, n_y))
                        visited[n_y][n_x] = 1


T=int(input())
for _ in range(T):
    l=int(input())
    chess = [[0 for _ in range(l)] for _ in range(l)]
    o_x,o_y=map(int, input().split())
    go_x,go_y=map(int, input().split())
    visited= [[-1 for _ in range(l)] for _ in range(l)]
    print(BFS(o_x, o_y))

