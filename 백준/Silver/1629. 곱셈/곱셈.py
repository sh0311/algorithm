A,B,C=map(int, input().split())


def con(A,B):
    if B==1:
        return A%C
    else:
        tmp=con(A,B//2)
        if B%2==0:
            return (tmp*tmp)%C
        else:
            return (tmp*tmp*A)%C

print(con(A,B))