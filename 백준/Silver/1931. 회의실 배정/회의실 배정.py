N=int(input())
li=[list(map(int, input().split())) for _ in range(N)]

li.sort(key=lambda x:(x[1],x[0]))

f=li[0][1]

cnt=1

for i in range(1,N):
    if li[i][0]>=f:
        f=li[i][1]
        cnt+=1

print(cnt)
