/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]={1,0,-1,0}; //오아왼위
int dy[4]={0,1,0,-1};

int sol(vector<vector<int>> &box, int n, int m, queue<pair<int, int>> &tomato){
    
    vector<vector<int>> res(n, vector<int>(m,0));
    int ans=0;
    
    while(!tomato.empty()){
        int y=tomato.front().first;
        int x=tomato.front().second;
        tomato.pop();
        
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            if(nx>=0&&nx<m && ny>=0&&ny<n && box[ny][nx]==0 && res[ny][nx]==0){
                res[ny][nx]=res[y][x]+1;
                box[ny][nx]=1;
                ans=max(ans, res[ny][nx]);
                tomato.push({ny,nx});
            }
        }
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(box[i][j]==0){
                return -1;
            }
        }
    return ans;
}

int main()
{
    int m,n;
    cin>>m>>n;
    
    vector<vector<int>> box(n,vector<int>(m));
    queue<pair<int, int>> tomato;
    
    bool zero=false;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>box[i][j];
            if(box[i][j]==1){
                tomato.push({i,j});
            }
            else if(box[i][j]==0){
                zero=true;
            }
        }
        
    if(!zero){
        cout<<0;
    }
    else{
        int res=sol(box,n,m,tomato);
        cout<<res;
    }

    return 0;
}