N=int(input())
li=[]
for _ in range(N):
    li.append(list(map(int, input().split())))

count1=0
count0=0
count_min=0

def square(x,y,len):
    global count1,count0,count_min
    stan=li[y][x]
    for i in range(y,y+len):
        for j in range(x, x+len):
            if (stan!=li[i][j]):
                for a in range(3):
                    for b in range(3):
                        square(x+len//3*a,y+len//3*b,len//3)
                return
    if stan==1:
        count1 +=1
    elif stan==0:
        count0 +=1
    else:
        count_min +=1

square(0,0,N)
print(count_min)
print(count0)
print(count1)
