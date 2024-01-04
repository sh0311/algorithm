N=int(input())

tree=[[] for _ in range(N)]
for i in range(N):
    n,l,r=input().split()
    tree[i].append(n)
    tree[i].append(l)
    tree[i].append(r)

def DFSF(tree,n):
    if n!='.':
        print(n,end='')
        for i in range(N):
            if tree[i][0]==n:
                idx=i
                l=tree[idx][1]
                r=tree[idx][2]
                DFSF(tree,l)
                DFSF(tree,r)

def DFSM(tree,n):
    if n != '.':
        for i in range(N):
            if tree[i][0]==n:
                idx=i
                l=tree[idx][1]
                r=tree[idx][2]
                DFSM(tree,l)
                print(n,end='')
                DFSM(tree,r)

def DFSL(tree,n):
    if n != '.':
        for i in range(N):
            if tree[i][0]==n:
                idx=i
                l=tree[idx][1]
                r=tree[idx][2]
                DFSL(tree,l)
                DFSL(tree,r)
                print(n, end='')

DFSF(tree,'A')
print()
DFSM(tree,'A')
print()
DFSL(tree,'A')