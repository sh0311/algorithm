li=['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
a=input()
count=0
i=0
while i<=len(a)-1:
    if a[i:i+3] in li:
        count+=1
        i+=3
    elif a[i:i+2] in li:
        count+=1
        i+=2
    else:
        count+=1
        i+=1
print(count)

