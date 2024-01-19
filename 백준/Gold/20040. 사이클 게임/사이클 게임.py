import sys

n,m=map(int, sys.stdin.readline().split())
parent=[i for i in range(n+1)]

cnt=0
num=0

def find(x):
    if parent[x]==x:
        return x
    parent[x]=find(parent[x])
    return parent[x]

def union(a,b):
    pa=find(a)
    pb=find(b)

    if pa==pb:
        return
    else:
        if pa<pb:
            parent[pb]=pa
        else:
            parent[pa]=pb
    return

for _ in range(m):
    a,b=map(int, sys.stdin.readline().split())

    cnt+=1
    if find(a)==find(b):
        num=cnt
        break
    union(a,b)

print(num)