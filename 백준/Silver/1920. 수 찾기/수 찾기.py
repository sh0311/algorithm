N=int(input())
A=list(map(int,input().split()))
A.sort()
M=int(input())
B=list(map(int,input().split()))


def bin(key,A,start,end):
    if start>end:
        print(0)
    else:
        mid=(start+end)//2

        if key<A[mid]:
            end=mid-1
            return bin(key, A, start, end)
        elif key>A[mid]:
            start=mid+1
            return bin(key, A, start, end)
        else:
            print(1)
            return


for i in B:
    bin(i,A,0,N-1)

