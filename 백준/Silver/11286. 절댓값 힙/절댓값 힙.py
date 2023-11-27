import heapq
import sys

q=[]

N=int(input())
for _ in range(N):
    a=int(sys.stdin.readline())
    if a==0:
        if not q:
            print(0)
        else:
            print(heapq.heappop(q)[1])
    elif a>0:
        heapq.heappush(q,(a,a))
    elif a<0:
        heapq.heappush(q,(-a,a))
