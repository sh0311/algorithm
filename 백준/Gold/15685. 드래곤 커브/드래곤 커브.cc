#include <iostream>
#include <vector>
#include <stack>


using namespace std;

#define MAX 101

int graph[MAX][MAX];

int dx[4]={1, 0, -1, 0};
int dy[4]={0,-1, 0, 1};

/*
0  //0
0 1  //1
0 1 2 1  //2
0 1 2 1 2 3 2 1  //3

*/

void dragon(pair<int, int> val, int d, int g) {
    int x=val.first;
    int y=val.second;

    graph[y][x]=1;

    //방향 담기
    vector<int> dirs;

    dirs.push_back(d);

    while(g>0) {
        // 이전 단계의 원소를 모두 stack에 담기
        stack<int> previous;
        for(int i=0;i<dirs.size();i++) {
            previous.push(dirs[i]);
        }
        // (stack의 가장 top(마지막)원소 + 1) % 4 을 dirs에 push + stack pop
        while(!previous.empty()) {
            dirs.push_back((previous.top()+1)%4);
            previous.pop();
        }
        g--;
    }


    //좌표 방문 처리
    int n_x=x;
    int n_y=y;

    for(int i=0;i<dirs.size();i++) {
        n_x=n_x+dx[dirs[i]];
        n_y=n_y+dy[dirs[i]];

        graph[n_y][n_x]=1;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;

    for(int i=0;i<N;i++) {
        int x, y, d, g;
        cin>>x>>y>>d>>g;

        dragon({x,y}, d, g); //방문하게 되는 곳들 표시
    }

    int cnt=0;

    for(int i=0;i<MAX-1;i++) {
        for(int j=0;j<MAX-1;j++) {
            if(graph[i][j]==1 && graph[i+1][j]==1 && graph[i+1][j+1]==1 && graph[i][j+1]==1) {
                cnt++;
            }
        }
    }
    cout<<cnt;

    return 0;
}