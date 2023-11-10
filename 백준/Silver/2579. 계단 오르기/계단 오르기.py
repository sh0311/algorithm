n=int(input())
arr=[0]*301
dp=[0]*301

for i in range(1,n+1):
    arr[i]=int(input())
dp[1]=arr[1]
dp[2]=dp[1]+arr[2]
dp[3] = max(arr[1] + arr[3], arr[2] + arr[3])


for n in range(4,n+1):
    dp[n]=max(dp[n-2]+arr[n],dp[n-3]+arr[n-1]+arr[n])
print(dp[n])