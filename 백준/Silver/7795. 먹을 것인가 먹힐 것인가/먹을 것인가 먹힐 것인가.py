def binary(li,a):
    low=0
    high=len(li)-1
    idx=-1
    while low<=high:
        mid=(low+high)//2
        if a>li[mid]:
            idx=mid
            low=mid+1
        else:
            high=mid-1
    return idx



T=int(input())
for _ in range(T):
    N,M=map(int, input().split())
    A=list(map(int, input().split()))
    B = list(map(int, input().split()))
    B.sort()
    low=0
    high=len(B)-1
    cnt=0
    for i in A:
        cnt+=binary(B,i)+1
    print(cnt)