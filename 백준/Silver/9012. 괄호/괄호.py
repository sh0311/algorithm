import sys

T = int(sys.stdin.readline())


for _ in range(T):
    D = sys.stdin.readline().strip()
    stack = []
    for p in D:
        if p == '(':
            stack.append(p)
        else:
            if len(stack):
                stack.pop()
            else:
                print('NO')
                break
    else:
        if stack:
            print('NO')
        else:
            print('YES')