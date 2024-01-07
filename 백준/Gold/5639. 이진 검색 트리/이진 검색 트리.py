import sys
sys.setrecursionlimit(10 ** 9)
input = sys.stdin.readline

tree = []
while True:
    try:
        tree.append(int(input()))
    except:
        break

def post(start, end):
    if start > end:
        return
    mid = end + 1
    for i in range(start + 1, end + 1):
        if tree[i] > tree[start]:
            mid = i
            break
    post(start + 1, mid - 1) #왼쪽 트리
    post(mid, end) #오른쪽 트리
    print(tree[start]) #루트 노드

post(0, len(tree) - 1)