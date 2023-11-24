N,M=map(int,input().split())
li=list(map(int, input().split()))
li.sort()

start=0
end=max(li)


result=0

while start<=end:
    mid=(start+end)//2
    total=0
    for l in li:
        if l>mid:
            total+=l-mid
    if total<M:
        end=mid-1
    else:
        result=mid
        start=mid+1

print(result)
