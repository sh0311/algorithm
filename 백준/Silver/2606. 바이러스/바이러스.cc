#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(vector<vector<int>>& graph, int now, vector<bool>& visited){
    queue<int> res;
    visited[now]=true;
    res.push(now);
    int cnt=0;
    while(!res.empty()){
        int val=res.front();
        res.pop();
        for(int i=0;i<graph[val].size();i++){
            int target=graph[val][i];
            if(!visited[target]){
                visited[target]=true;
                res.push(target);
                cnt+=1;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int com,direct;
    cin>>com>>direct;

    vector<vector<int>> graph(com+1);

    for(int i=0;i<direct;i++){
        int first,second;
        cin>>first>>second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    vector<bool> visited(com+1, false);

    int res=bfs(graph, 1, visited);

    cout<<res;
}
