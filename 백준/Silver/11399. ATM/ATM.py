N=int(input())
time=list(map(int, input().split()))


for i in range(N):
    for j in range(i+1,N):
        if time[i]>time[j]:
            time[i],time[j]=time[j],time[i]
sum=0
total=0
for t in time:
    sum+=t
    total+=sum
print(total)