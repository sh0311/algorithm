#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

static int graph[101][101];
static int visited[101][101]={false};
void BFS(int i, int j);
static int dx[]={0,0,-1,1};
static int dy[]={-1,1,0,0};
static int n, m;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            graph[i][j]=s[j]-'0';
        }
    }
    BFS(0,0);
    cout<<graph[n-1][m-1];

}


void BFS(int i, int j){
    queue<pair<int, int>> que;
    que.push(make_pair(i,j));
    while(!que.empty()){
        int now[2];
        now[0]=que.front().first;
        now[1]=que.front().second;
        que.pop();
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int x=now[0]+dx[k];
            int y= now[1]+dy[k];
            if(x>=0&&y>=0&&x<n&&y<m){
                if(!visited[x][y]&&graph[x][y]!=0){
                    que.push(make_pair(x,y));
                    graph[x][y]=graph[now[0]][now[1]]+1;
                    visited[x][y]=true;
            }

            }

            }

    }
}


