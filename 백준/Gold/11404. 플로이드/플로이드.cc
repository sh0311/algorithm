/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF=1e7;

void floyd(vector<vector<int>> &graph, int n){
    
    //플로이드
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j]=min(graph[i][k]+graph[k][j], graph[i][j]);
            }
        }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    
    for(int i=1;i<=n;i++){
        graph[i][i]=0;
    }
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=min(graph[a][b],c);
    }
    
    floyd(graph,n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}