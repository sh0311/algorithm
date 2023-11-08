N=int(input())
time=list(map(int, input().split()))

time.sort()
sum=0
total=0
for t in time:
    sum+=t
    total+=sum
print(total)