/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int dx[4]={0,1,0,-1}; //위오아왼
int dy[4]={-1,0,1,0};

using namespace std;


int sol(vector<vector<int>> &graph, int n, int m){
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    vector<vector<int>> res(n,vector<int>(m, 1e9));
    
    queue<pair<int,int>> q;
    visited[0][0]=true;
    q.push({0,0});  //x,y
    res[0][0]=1;

    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0&&nx<m && ny>=0&&ny<n && !visited[ny][nx] && graph[ny][nx]==1){
                visited[ny][nx]=true;
                q.push({nx,ny});
                res[ny][nx]=res[y][x]+1;
            }
        }
    }
    return res[n-1][m-1];
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> graph(n, vector<int>(m));
    
    for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                graph[i][j]=s[j]-'0';
            }
        }
    
    int res=sol(graph, n, m);
    cout<<res;
    

    return 0;
}