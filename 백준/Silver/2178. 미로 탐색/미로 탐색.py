from collections import deque

N,M=map(int, input().split())
road=[]
for _ in range(N):
    li=list(map(int,input()))
    road.append(li)
visited=[[-1 for _ in range(M)] for _ in range(N)]



def BFS(i,j,road):
    deq=deque([(i,j)])


    dx=[1,-1,0,0]
    dy=[0,0,1,-1]

    while(deq):
        tmp=deq.popleft()

        for a in range(4):
            i2 = tmp[0] + dx[a]
            j2 = tmp[1] + dy[a]

            if i2<0 or i2>N-1 or j2<0 or j2>M-1:
                continue
                
            if road[i2][j2] == 1:
                road[i2][j2]=road[tmp[0]][tmp[1]]+1
                deq.append((i2,j2))




BFS(0,0,road)
print(road[N-1][M-1])