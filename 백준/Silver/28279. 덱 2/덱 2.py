from _collections import deque
import sys

deq=deque()
N=int(input())
for _ in range(N):
    a=list(map(int, sys.stdin.readline().strip().split()))

    if a[0]==1:
        deq.appendleft(a[1])
    elif a[0]==2:
        deq.append(a[1])
    elif a[0]==3:
        if deq:
            print(deq.popleft())
        else:
            print(-1)
    elif a[0]==4:
        if deq:
            print(deq.pop())
        else:
            print(-1)
    elif a[0]==5:
        print(len(deq))
    elif a[0]==6:
        if not deq:
            print(1)
        else:
            print(0)
    elif a[0]==7:
        if deq:
            print(deq[0])
        else:
            print(-1)
    elif a[0]==8:
        if deq:
            print(deq[-1])
        else:
            print(-1)