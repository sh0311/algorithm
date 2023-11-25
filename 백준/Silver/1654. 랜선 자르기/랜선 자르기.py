K,N=map(int, input().split())
li=[int(input()) for _ in range(K)]
li.sort()

start=1
end=max(li)

result=0

while start<=end:
    cnt = 0
    mid=(start+end)//2
    for l in li:
        cnt+=(l//mid)
    if cnt<N:
        end=mid-1
    else:
        result=mid
        start=mid+1
print(result)

