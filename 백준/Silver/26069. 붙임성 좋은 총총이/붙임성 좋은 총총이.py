import sys
N=int(input())
li=[]
for _ in range(N):
    a,b=sys.stdin.readline().strip().split()
    if a=='ChongChong' or b =='ChongChong':
         li.append(a)
         li.append(b)
    elif a in li or b in li:
        li.append(a)
        li.append(b)
    else:
        continue
fin=set(li)
print(len(fin))
