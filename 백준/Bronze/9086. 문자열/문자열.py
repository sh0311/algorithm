a=int(input())
S=[]
for i in range(a):
    s=input()
    S.append(s)
for i in range(a):
    print(S[i][0],end='')
    print(S[i][-1])