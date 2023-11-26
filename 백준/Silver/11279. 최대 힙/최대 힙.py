import heapq
import sys

N=int(input())
heap=[]

for _ in range(N):
    a=int(sys.stdin.readline())
    if a>0:
        heapq.heappush(heap, -a)
    elif a==0:
        if not heap:
            print(0)
        else:
            print(-heapq.heappop(heap))


