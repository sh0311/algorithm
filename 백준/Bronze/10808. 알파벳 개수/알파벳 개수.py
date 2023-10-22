S=input()
li=['a', 'b','c','d','e','f','g','h','i','j', 'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
res=[0]*26

for s in S:
    for i in range(len(li)):
        if s==li[i]:
            res[i]+=1
for r in res:
    print(r, end=' ')