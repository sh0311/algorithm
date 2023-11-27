import heapq
import sys
N=int(input())

q=[]

for _ in range(N):
    a=int(sys.stdin.readline())
    if a>0:
        heapq.heappush(q,a)
    else:
        if not q:
            print(0)
        else:
            res=heapq.heappop(q)
            print(res)
