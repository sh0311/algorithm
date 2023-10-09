li=[]
sum=0
for _ in range(5):
    a=int(input())
    sum+=a
    li.append(a)
print(int(sum/5))
for i in range(5):
    for j in range(i+1,5):
        if li[i]>li[j]:
            li[i],li[j]=li[j],li[i]
print(li[2])