N=int(input())

li=[list(map(int, input())) for _ in range(N)]

visited=[[-1 for _ in range(N)] for _ in range(N)]

result=[]

def DFS(li, visited, i, j):
    global cnt

    dx=[1,-1,0,0]
    dy=[0,0,1,-1]
    for a in range(4):
        i2=i+dx[a]
        j2=j+dy[a]
        if i2>=0 and i2<N:
            if j2>=0 and j2<N:
                if li[i2][j2]==1 and visited[i2][j2]==-1:
                    cnt+=1
                    visited[i2][j2]=1
                    DFS(li, visited, i2, j2)


num=0
for i in range(N):
    for j in range(N):
        if li[i][j]==1 and visited[i][j]==-1:
            num+=1
            cnt = 1
            visited[i][j]=1
            DFS(li, visited, i, j)
            result.append(cnt)

print(num)
result.sort()
for i in range(len(result)):
    print(result[i])
