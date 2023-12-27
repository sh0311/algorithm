from collections import deque

def BFS():
    dx=[1,-1,0,0]
    dy=[0,0,1,-1]

    while deq:
        t=deq.popleft()
        for i in range(4):
            ny = t[0] + dy[i]
            nx = t[1] + dx[i]
            if ny >= 0 and ny < N:
                if nx >= 0 and nx < M:
                    if box[ny][nx] == 0:
                        box[ny][nx] = box[t[0]][t[1]] + 1
                        deq.append((ny, nx))


M,N=map(int,input().split())
box=[]
for _ in range(N):
    box.append(list(map(int, input().split())))

deq=deque()

for i in range(N):
    for j in range(M):
        if box[i][j] == 1:
            deq.append((i,j))
BFS()

m=0
for i in box:
    for j in i:
        if j==0:
            print(-1)
            exit()
    else:
        m=max(m,max(i))

print(m-1)