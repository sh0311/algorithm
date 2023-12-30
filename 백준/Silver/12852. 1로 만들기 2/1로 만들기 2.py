N=int(input())
dp=[0]*(N+1)

for i in range(2,N+1):
    dp[i]=dp[i-1]+1
    if i%2==0:
        dp[i]=min(dp[i],dp[i//2]+1)
    if i%3==0:
        dp[i]=min(dp[i],dp[i//3]+1)


print(dp[N])
num=dp[N]

res=[N]
while num>0:
    if num==1:
        res.append(1)
        break
    else:
        if N%6==0:
            if dp[N//2]==num-1:
                num = dp[N // 2]
                N=N//2


            elif dp[N // 3] == num - 1:
                num = dp[N // 3]
                N = N // 3

            res.append(N)
        elif N%2==0:
            if dp[N//2]==num-1:
                num = dp[N // 2]
                N = N // 2

            elif dp[N-1]==num-1:
                num = dp[N - 1]
                N = N -1

            res.append(N)
        elif N%3==0:
            if dp[N//3]==num-1:
                num = dp[N // 3]
                N = N // 3

            elif dp[N - 1] == num - 1:
                num = dp[N - 1]
                N = N -1

            res.append(N)
        else:
            num = dp[N - 1]
            N=N-1
            res.append(N)

for r in res:
    print(r, end=' ')