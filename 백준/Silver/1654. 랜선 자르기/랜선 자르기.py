k, n = map(int, input().split())
lan = []
for _ in range(k):
    lan.append(int(input()))

start = 1
end = max(lan)
result = 0

while start <= end:
    cnt = 0
    mid = (start + end) // 2

    for i in lan:
        cnt += (i // mid)

    if cnt >= n:
        result = mid
        start = mid + 1

    else:
        end = mid - 1

print(result)