N,M=map(int, input().split())
li=[]
for i in range(N):
    li.append(list(map(int,input().split())))
M,K=map(int, input().split())
li2=[]
for i in range(M):
    li2.append(list(map(int,input().split())))

new=[]
for j in range(K):
    temp=[]
    for p in range(len(li2)):
        temp.append(li2[p][j])
    new.append(temp)

fin=[]
for i in range(N):
    fin_row=[]
    for j in range(len(new)):
        tem=0
        for k in range(M):
            tem+=li[i][k]*new[j][k]
        fin_row.append(tem)
    fin.append(fin_row)

for i in range(N):
    for j in range(len(new)):
        print(fin[i][j], end=' ')
    print('')