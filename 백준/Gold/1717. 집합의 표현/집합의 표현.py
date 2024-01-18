import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

n,m=map(int,input().split())

parent=[i for i in range(n+1)]

def find(x):
    if parent[x]==x:
        return x
    parent[x]=find(parent[x])
    return parent[x]

def union(x,y):
    px=find(x)
    py=find(y)
    if px==py:
        return
    if px<py:
        parent[py]=px
    else:
        parent[px]=py
    return

for _ in range(m):
    a,b,c=map(int, input().split())
    if a==0:
        union(b,c)
    else:
        pb=find(b)
        pc=find(c)
        if pb==pc:
            print('YES')
        else:
            print('NO')

