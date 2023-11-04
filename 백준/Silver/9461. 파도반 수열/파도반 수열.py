def dp(n):

    p[1]=1
    p[2] = 1
    p[3] = 1
    p[4] = 2
    p[5] = 2
    for i in range(6, n+1):
        p[i]=p[i-1]+p[i-5]
    return(p[n])

N=int(input())
p=[0]*101
for _ in range(N):
    n=int(input())
    print(dp(n))