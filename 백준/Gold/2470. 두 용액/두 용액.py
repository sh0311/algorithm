N=int(input())
li=[int(x) for x in input().split()]
li.sort()

i=0
j=len(li)-1

cal=[]
m=abs(li[i]+li[j])
m1=li[0]
m2=li[j]

while i<j:
    if m > abs(li[i] + li[j]):
        m = abs(li[i] + li[j])
        m1 = li[i]
        m2 = li[j]
    if li[i]+li[j]>0:
        j-=1
    elif li[i]+li[j]<0:
        i+=1
    else:
        break




print(m1,m2)

