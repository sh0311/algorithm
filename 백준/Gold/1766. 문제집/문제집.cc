#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> sol(vector<vector<int>> &graph, vector<int> &indegree) {

    priority_queue<int, vector<int>, greater<>> pq; // 최소힙
    vector<int> result(0);

    for(int i=1;i<indegree.size();i++) {
        if(indegree[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int now=pq.top();
        result.push_back(now);
        pq.pop();

        for(int i=0;i<graph[now].size();i++) {
            int next=graph[now][i];
            indegree[next]--;
            if(indegree[next]==0) {
                pq.push(next);
            }
        }
    }

    return result;
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1,vector<int>(0));
    vector<int> indegree(n+1);

    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        indegree[b]++;
    }

    vector<int> res=sol(graph, indegree);

    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<" ";
    }



    return 0;
}
