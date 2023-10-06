N,M=map(int, input().split())
li=[]
li2=[]

for _ in range(N):
    li.append(input().split())
for _ in range(N):
    li2.append(input().split())
for i in range(N):
    for j in range(M):
        print(int(li[i][j])+int(li2[i][j]),end=' ')
    print()
