def dp(n):
    if n==1:
        print(1)
    elif n==2:
        print(1)
    elif n==3:
        print(1)
    elif n==4:
        print(2)
    elif n==5:
        print(2)
    elif n>5:
        p=[0]*(n+1)
        p[1]=1
        p[2] = 1
        p[3] = 1
        p[4] = 2
        p[5] = 2
        for i in range(6, n+1):
            p[i]=p[i-1]+p[i-5]
        print(p[n])

N=int(input())
for _ in range(N):
    n=int(input())
    dp(n)