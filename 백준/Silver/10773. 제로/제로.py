import sys

li=[]
sum=0
K=int(input())
for _ in range(K):
    a=int(sys.stdin.readline())
    if a!=0:
        li.append(a)
    elif a==0:
        del li[-1]
for l in li:
    sum+=l
print(sum)
