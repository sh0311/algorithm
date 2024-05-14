#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int v);

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int m;
    cin>>m;

    A.resize(n+1);
    visited=vector<bool>(n+1, false);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    int count=0;

    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            DFS(i);
            count+=1;
        }
    }

    cout<<count<<'\n';

}
void DFS(int v){
    if(visited[v])
        return;
    visited[v]=true;
    for(int i:A[v]){
        if(visited[i]==false){
        DFS(i);}
    }
}