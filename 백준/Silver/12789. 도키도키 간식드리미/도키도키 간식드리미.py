from _collections import deque
import sys
N=int(input())
input=sys.stdin.readline()
a=deque(map(int, input.split()))
b=[]
i=1

while i<=N:
    if a and a[0]==i:
        i+=1
        a.popleft()
    elif b and b[-1]==i:
        i+=1
        b.pop()
    else:
        if a:
            b.append(a.popleft())
        elif not a:
            print('Sad')
            break

if not b:
    print('Nice')