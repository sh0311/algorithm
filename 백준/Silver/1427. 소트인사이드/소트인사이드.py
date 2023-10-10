a=list(input())
min=a[0]
for i in range(len(a)):
    for j in range(i+1, len(a)):
        if a[i]<a[j]:
            a[i],a[j]=a[j],a[i]
for i in range(len(a)):
    print(a[i],end='')