from _collections import deque
N=int(input())
a=deque(enumerate(map(int, input().split())))
li=[]

while a:
    idx, paper=a.popleft()
    li.append(idx+1)

    if paper>0:
        a.rotate(-(paper-1))
    elif paper<0:
        a.rotate(-paper)
for i in li:
    print(i,end=' ')
