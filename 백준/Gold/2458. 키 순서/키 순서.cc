#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int INF=2e5;

vector<vector<int>> floyd(vector<vector<int>> &height, int N) {
    for(int i=1;i<=N;i++) //중간정점
        for(int j=1;j<=N;j++) //출발정점
            for(int k=1;k<=N;k++) //도착정점
                {
                int cost=height[j][i]+height[i][k];
                height[j][k] = min(height[j][k], height[j][i] + height[i][k]);
                }
    return height;
}

bool check(int a, int b, vector<vector<int>> &height) {
    if(height[b][a]==INF)
        return false;

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin>>N>>M;

    vector<vector<int>> height(N+1, vector<int>(N+1, INF));

    for (int i = 1; i <= N; i++) {
        height[i][i] = 0;  // 자기 자신으로 가는 경로는 0
    }

    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;

        height[a][b]=1;
    }

    vector<vector<int>> res = floyd(height, N);

    int cnt=0;

    for(int i=1;i<=N;i++) {
        bool flag=true;
        for(int j=1;j<=N;j++) {
            if(height[i][j]==INF) {
                if(!check(i, j, height)) {
                    flag=false;
                    break;
                    }
                }
            }
        if(flag)
            cnt++;
        }


    cout<<cnt;

    return 0;
}