#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 4가지 방향만 확인 (가로, 세로, 대각선 두 방향)
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n,m;
vector<vector<int>> map;
vector<pair<int, int>> virus;
int ans=0;

void checkSafeZone(vector<vector<int>>& tmp_map){
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(tmp_map[i][j]==0)
                cnt+=1;
        }
    ans=max(ans, cnt);
}



void bfs(){
    queue<pair<int, int>> q;
    vector<vector<int>> tmp_map=map;

    for(auto& v: virus){
        q.push(v);
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (0 <= newx && newx < n && 0 <= newy && newy < m && tmp_map[newx][newy] == 0) {
                tmp_map[newx][newy] = 2;
                q.push(make_pair(newx, newy));
            }
        }
    }

    checkSafeZone(tmp_map);

}


void wall(int cnt){
    if(cnt==3){
        bfs();
        return;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(map[i][j]==0){
                map[i][j]=1;
                wall(cnt+1);
                map[i][j]=0; //bfs 끝나서 다시 시작 해야 하므로 reset 시켜줌
            }
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin>>n>>m;

    map.assign(n, vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                virus.push_back(make_pair(i,j));
            }

        }

    wall(0);

    cout<<ans;

}
