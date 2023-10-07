N,M=map(int, input().split())
li=list((map(int,input().split())))
sum=0
for i in range(N):
    for j in range(i+1,N):
        for k in range(j+1,N):
            if li[i]+li[j]+li[k]>M:
                continue
            else:
                sum=max(sum, li[i]+li[j]+li[k])
print(sum)