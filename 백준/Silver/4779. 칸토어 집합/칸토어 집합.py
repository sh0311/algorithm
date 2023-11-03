def small(s,p,q):
    cnt=(q-p+1)//3
    if cnt==0:
        return
    small(s, p, p+cnt-1)
    for i in range(p+cnt,p+cnt*2):
        s[i]=' '
    small(s,p+cnt*2, q)

while True:
    try:
        n=input()
        if n=='':
            break
        n=int(n)
        s=['-']*(3**n)
        small(s,0,len(s)-1)
        print(''.join(s))


    except EOFError:
        break
