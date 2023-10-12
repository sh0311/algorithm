N=int(input())
li=[]
for _ in range(N):
    li.append(input())
li=list(set(li))
li.sort()
li.sort(key=lambda x:len(x))
for i in li:
    print(i)