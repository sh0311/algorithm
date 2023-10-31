import sys

def recursion(s, l, r,c):

    if l>=r:
        print(1,c)
    elif s[l]!=s[r]:
        print(0, c)
    else:
        recursion(s, l+1, r-1,c+1)


def isPalindrome(s):
    recursion(s, 0, len(s)-1,1)

T=int(input())
for _ in range(T):
    s=sys.stdin.readline().strip()
    isPalindrome(s)