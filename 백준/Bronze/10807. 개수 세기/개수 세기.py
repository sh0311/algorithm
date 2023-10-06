n=int(input())
n_list=list(map(int, input().split()))
m=int(input())
count=0
for i in n_list:
    if m==i:
        count+=1
print(count)