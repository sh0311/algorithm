from collections import deque

N,K=map(int, input().split())
road=[0]*1000001
visited=[0]*1000001

def bfs(road,N,visited):
    deq=deque([N])
    visited[N]=1
    while deq:
        cri=deq.popleft()
        if cri==K:
            return road[cri]
        else:
            for i in (cri*2, cri+1, cri-1):
                if 0 <= i < 100001 and visited[i]==0:
                        road[i]=road[cri]+1
                        visited[i]=1
                        deq.append(i)

print(bfs(road,N,visited))