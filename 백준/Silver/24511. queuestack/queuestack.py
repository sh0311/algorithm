import sys
from _collections import deque

N=int(sys.stdin.readline())
A=list(map(int,sys.stdin.readline().split()))
B=list(map(int,sys.stdin.readline().split()))
C=int(sys.stdin.readline())
D=list(map(int,sys.stdin.readline().split()))

deq=deque()

for i in range(N):
    if A[i]==0:
        deq.appendleft(B[i])
for i in range(C):
    deq.append(D[i])
    print(deq.popleft(),end=' ')

