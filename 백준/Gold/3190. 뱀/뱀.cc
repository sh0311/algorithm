#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

int dx[]={1,0,-1,0}; // 오 아래 왼 위
int dy[]={0,1,0,-1};

int sol(vector<vector<int>> &board, vector<pair<int, char>> &dirs, deque<pair<int, int>> &snake, int board_size) {
    int headX=1;
    int headY=1;
    board[1][1] = 2;
    snake.push_back(make_pair(headX, headY));

    int cnt=0;
    int dirX=0;

    while(true) {

        int nextX = headX + dx[dirX];
        int nextY = headY + dy[dirX];
        cnt++;

        // 벽이나 자기 자신과 충돌하면 종료
        if (nextX <= 0 || nextY <= 0 || nextX > board_size || nextY > board_size || board[nextY][nextX] == 2) {
            return cnt; 
        }
        // 머리 이동
        headX = nextX;
        headY = nextY;

        //사과가 있다면
        if(board[headY][headX]==1) {
            board[headY][headX] = 2;
            snake.push_back(make_pair(headX,headY));
        }

        //사과가 없다면
        else if(board[headY][headX]==0) {
            board[headY][headX] = 2;
            snake.push_back(make_pair(headX,headY));
            board[snake.front().second][snake.front().first] = 0;
            snake.pop_front();
        }

        //방향 결정
        if(!dirs.empty() && dirs[0].first==cnt) {

                //D
                if(dirs[0].second=='D') {
                    dirX=(dirX+1)%4;
                }

                //L
                else if(dirs[0].second=='L') {
                    dirX=(dirX+3)%4;
                }
                dirs.erase(dirs.begin());

        }

    }
    return cnt;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int board_size, apple;
    cin >> board_size >> apple;

    vector<vector<int>> board(board_size+1, vector<int>(board_size+1, 0));

    for(int i=0;i<apple;i++) {
        int x,y;
        cin>>y>>x;
        board[y][x]=1;
    }

    int num;
    cin>>num;
    vector<pair<int, char>> dirs;

    for(int i=0;i<num;i++) {
        int second;
        char dir;
        cin>>second>>dir;

        dirs.push_back(make_pair(second,dir));
    }

    deque<pair<int, int>> snake;
    int res=sol(board, dirs, snake, board_size);

    cout<<res<<'\n';
    return 0;
}