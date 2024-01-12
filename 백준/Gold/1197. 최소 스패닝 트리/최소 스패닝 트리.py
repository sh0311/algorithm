import sys

V,E=map(int, sys.stdin.readline().split())
graph=[[]for _ in range(E)]
parent=[i for i in range(V+1)]
mst=0

for i in range(E):
    a,b,c=map(int, sys.stdin.readline().split())
    graph[i]=[a,b,c]

graph.sort(key=lambda x : x[2])

def find(x):
    if x==parent[x]:
        return parent[x]
    return find(parent[x])
for g in graph:
    x=g[0]
    y=g[1]
    px=find(x)
    py=find(y)
    if px!=py:
        if px<py:
            parent[py]=px

        elif px>py:
            parent[px]=py

        mst+=g[2]
    if parent[1:]==[1]:
        break

print(mst)