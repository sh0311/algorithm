from sys import stdin
N = stdin.readline()
A = sorted(map(int,stdin.readline().split()))
M = stdin.readline()
B = map(int,stdin.readline().split())

def binary(key, N, start, end):
    if start > end:
        return 0
    mid = (start+end)//2
    if key == A[mid]:
        i, j = 1, 1
        while mid-i >= start:
            if A[mid-i] != A[mid]:
                break
            else: i += 1
        while mid+j <= end:
            if A[mid+j] != A[mid]:
                break
            else: j += 1
        return i + j - 1
    elif key < A[mid]:
        return binary(key, A, start, mid-1)
    else:
        return binary(key, A, mid+1, end)

n_dic = {}
for a in A:
    start = 0
    end = len(A)-1
    if a not in n_dic:
        n_dic[a] = binary(a, A, start, end)

print(' '.join(str(n_dic[x]) if x in n_dic else '0' for x in B ))