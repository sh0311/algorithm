
import sys
input = sys.stdin.readline

n = int(input())
img_list = [list(map(int, input().strip())) for _ in range(n)]

def check_img(x, y, n):
    num = img_list[x][y]
    for i in range(x, x+ n):
        for j in range(y, y + n):
            if img_list[i][j] != num:
                print("(", end='')
                n = n // 2
                check_img(x, y, n)
                check_img(x, y + n, n)
                check_img(x + n, y, n)
                check_img(x + n, y + n, n)
                print(")", end='')
                return
    if num == 1:
        print(1, end='')
    else:
        print(0, end='')


check_img(0, 0, n)