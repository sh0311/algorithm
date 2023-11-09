n=int(input())
S=list(map(int, input().split()))
dp=[S[0]]*len(S)

for i in range(1, len(S)):
    dp[i]=max(S[i], S[i]+dp[i-1])
print(max(dp))