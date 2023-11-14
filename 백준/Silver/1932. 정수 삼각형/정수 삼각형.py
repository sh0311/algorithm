n=int(input())

dp=[]
for _ in range(n):
    dp.append(list(map(int, input().split())))
for a in range(1,n):
    for b in range(len(dp[a])):
        if b==0:
            dp[a][b]=dp[a-1][b]+dp[a][b]
        elif b==len(dp[a])-1:
            dp[a][b] = dp[a-1][b-1] + dp[a][b]
        else:
            dp[a][b]=max(dp[a-1][b-1]+dp[a][b],dp[a-1][b]+dp[a][b])
print(max(dp[n-1]))