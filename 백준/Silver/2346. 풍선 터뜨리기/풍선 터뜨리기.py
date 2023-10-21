N=int(input())
a=list(map(int, input().split()))

index=[i for i in range(1,N+1)]
li=[]
idx=0
tmp=a.pop(idx) #idx 인덱스에 있는 값을 꺼내줌
li.append(index.pop(idx))

while a:
    if tmp>0:
        idx=(idx+tmp-1)%len(a)
    else:
        idx=(idx+tmp)%len(a)
    tmp=a.pop(idx)
    li.append(index.pop(idx))
for i in li:
    print(i, end=' ')