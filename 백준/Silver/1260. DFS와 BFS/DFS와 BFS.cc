#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

static vector<vector<int>> vec;
void DFS(int start);
void BFS(int start);
static vector<bool> visited;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v;
    cin>>n>>m>>v;

    vec.resize(n+1);
    visited=vector<bool>(n+1, false);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(), vec[i].end());
    }

    DFS(v);
    cout<<'\n';
    fill(visited.begin(), visited.end(), false);
    BFS(v);


}

void DFS(int start){
    if(visited[start])
        return;
    visited[start]=true;
    cout<<start<<" ";
    for(int i:vec[start]){
            DFS(i);
    }
}

void BFS(int start){
    queue<int> queue;
    queue.push(start);
    visited[start]=true;
    while(!queue.empty()){
        int val=queue.front();
        queue.pop();
        cout<<val<<" ";
        for(int i:vec[val]){
            if(!visited[i]){
                queue.push(i);
                visited[i]=true;
            }
        }
    }
}


