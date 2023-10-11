n=int(input())
li=[]
for i in range(n):
    a,b=input().split()
    li.append([a,b])
li.sort(key=lambda x:int(x[0]))
for l in li:
    print(l[0],l[1])