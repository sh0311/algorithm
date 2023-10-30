import sys

N = int(input())
li = set()
count = 0

for _ in range(N):
    inp = sys.stdin.readline().strip()  # strip() 함수로 개행 문자 제거
    if inp == 'ENTER':
        li.clear()
    else:
        if inp in li:
            continue
        else:
            li.add(inp)
            count += 1

print(count)