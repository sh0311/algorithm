#include <iostream>
#include <vector>

using namespace std;

// 4가지 방향만 확인 (가로, 세로, 대각선 두 방향)
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(vector<vector<char>>& color, int x, int y, vector<vector<bool>>& visited){
    char target=color[x][y];
    for(int i=0;i<4;i++){
        int new_x=x+dx[i];
        int new_y=y+dy[i];

        if(new_x>=0 && new_x<color.size() && new_y >= 0 && new_y < color.size()){
            if(color[new_x][new_y]==target && !visited[new_x][new_y]){
                visited[new_x][new_y]=true;
                dfs(color, new_x, new_y, visited);
            }
        }
    }
}

void dfs2(vector<vector<char>>& color, int x, int y, vector<vector<bool>>& visited){
    char target=color[x][y];

    for(int i=0;i<4;i++){
        int new_x=x+dx[i];
        int new_y=y+dy[i];

        if(new_x>=0 && new_x<color.size() && new_y >= 0 && new_y < color.size()){
            if(!visited[new_x][new_y]){
                if(target=='B'){
                    if(color[new_x][new_y]==target){
                        visited[new_x][new_y]=true;
                        dfs(color, new_x, new_y, visited);
                    }
                }
                else if(target=='G'||target=='R'){
                    if(color[new_x][new_y]=='R'||color[new_x][new_y]=='G'){
                        visited[new_x][new_y]=true;
                        dfs2(color, new_x, new_y, visited);
                    }
                }
            }

        }
        }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<char>> color(n, vector<char>(n));
    vector<vector<bool>> visited(n, vector<bool>(n,false));

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            color[i][j]=s[j];
        }
    }

    int cnt=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                cnt+=1;
                dfs(color, i, j, visited);
            }
        }

    for(int i=0;i<n;i++){
            fill(visited[i].begin(), visited[i].end(), false);
        }

    int cnt2=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                cnt2+=1;
                dfs2(color, i, j, visited);
            }
        }


    cout<<cnt<<" "<<cnt2;

}
