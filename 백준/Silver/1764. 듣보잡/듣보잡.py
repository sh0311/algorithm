dic={}
n,m=map(int, input().split())
cnt=0
li=[]

for _ in range(n):
    l=input()
    dic[l]=1
for _ in range(m):
    s=input()
    if s in dic:
        dic[s]+=1
    else:
        dic[s]=0

for i in dic:
    if dic[i]>1:
        cnt+=1
        li.append(i)

print(cnt)
li.sort()
for l in li:
    print(l)