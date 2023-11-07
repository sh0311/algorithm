S=input().split('-')


val = 0
tem=S[0].split('+')
for i in tem:
    val+=int(i)

if len(S)>1:
    for i in range(1, len(S)):
        tem=S[i].split('+')
        sum = 0
        for i in tem:
            sum += int(i)
        val -= sum
print(val)