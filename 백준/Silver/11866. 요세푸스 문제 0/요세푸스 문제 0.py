from _collections import deque
N, K=map(int,input().split())

li=deque([i for i in range(1,N+1)])
re=[]

while li:
    for i in range(K-1):
        li.append(li.popleft())
    re.append(li.popleft())
print('<',end='')
for i in range(N-1):
    print(re[i],end=', ')
print(re[-1],end='')
print('>', end='')