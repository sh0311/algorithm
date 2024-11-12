#include <iostream>
#include <vector>


using namespace std;
bool visited[50][50]={false};
int dx[4]={0, 1, 0, -1};  // 북 동 남 서 순서
int dy[4]={-1, 0, 1, 0};

bool around(int x, int y, int N, int M, vector<vector<int> > &raod) {
    for(int i=0; i<4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x>= 0 && new_x < M && new_y >= 0 && new_y < N &&
            !visited[new_y][new_x] && raod[new_y][new_x] == 0) {
            return true;
            }
    }
    return false;
}


int sol(vector<vector<int>>& road, int r, int c, int d, int N, int M) {
    visited[r][c]=true;
    int cnt=1;

    while(true) {
        if (around(c, r, N, M, road)) {
            //다음 방향(반시계)
            for(int i=0; i<4; i++) {
                d=(d+3)%4;
                int new_x=c+dx[d];
                int new_y=r+dy[d];

                if(new_x>= 0 && new_x < M && new_y >= 0 && new_y < N &&
                    !visited[new_y][new_x] && road[new_y][new_x]==0) {

                    visited[new_y][new_x]=true;
                    c=new_x;
                    r=new_y;
                    cnt++;
                    break;
                    }
            }
        }
        //주위에 빈 칸 없으면
        else {
            int back_d=(d+2)%4;
            int new_x=c+dx[back_d];
            int new_y=r+dy[back_d];
            if(new_x < 0 || new_x >= M || new_y < 0 || new_y >= N ||
                road[new_y][new_x]==1) {
                break;
                }
            c=new_x;
            r=new_y;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    int r,c,d;
    cin>>r>>c>>d;

    vector<vector<int>> road(N,vector<int>(M));

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) {
            cin>>road[i][j];
        }


    int res=sol(road, r, c, d, N, M);
    cout<<res;

    return 0;

}
