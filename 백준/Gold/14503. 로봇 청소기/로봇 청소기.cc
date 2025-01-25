/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int dx[4]={0,1,0,-1}; //북, 서, 남, 동
int dy[4]={-1,0,1,0};
vector<vector<int>> graph;
int cnt=0;
int n,m;

void sol(int r,int c, int d){
    int now=graph[r][c];
    if(now==0){
        graph[r][c]=2;
        cnt++;
    }
    
    //청소되지 않은 칸 있는 경우
    for(int i=0;i<4;i++){
        d=(d+3)%4;
        int nextX=c+dx[d];
        int nextY=r+dy[d];
        if(graph[nextY][nextX]==0){
            r=nextY;
            c=nextX;
            sol(r,c,d);
            return;
        }
    }
    
    //청소되지 않은 칸 없는 경우
    int back=graph[r+dy[(d+2)%4]][c+dx[(d+2)%4]];
    if(back==1||r+dy[(d+2)%4]<0||r+dy[(d+2)%4]>=n||c+dx[(d+2)%4]<0||c+dx[(d+2)%4]>=m){
        return;
    } 
    r=r+dy[(d+2)%4];
    c=c+dx[(d+2)%4];
    sol(r,c,d);
    return;
}




int main()
{
    cin>>n>>m;
    int r,c,d;
    cin>>r>>c>>d;
    
    graph.resize(n,vector<int>(m,-1));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    
    sol(r,c,d);

    
    cout<<cnt;
    return 0;
}