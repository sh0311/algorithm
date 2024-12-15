#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const long long INF = 1e6 + 1;
typedef pair<int, int> ci;

long long prim(int n, vector<vector<ci>>& graph, int start) {
    vector<long long> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    priority_queue<ci, vector<ci>, greater<> > pq;

    //시작점
    pq.push({0,start});
    long long sum=0;
    dist[start] = 0;

    while(!pq.empty()) {
        auto[val, cur]=pq.top();
        pq.pop();

        if(!visited[cur]) {
            visited[cur] = true;
            sum+=val;
            for(auto[nVal, next]:graph[cur]) {
                if(!visited[next] && dist[next]>nVal) {
                    dist[next] = nVal;
                    pq.push({nVal, next});
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            return -1;
        }
    }
    return sum;
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<ci>> graph(n+1);
    long long sum=0;

    for(int i=0;i<m;i++) {
        int a,b;
        long long c;
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
        sum+=c;
    }

    long long res=prim(n, graph, 1);

    if(res==-1) {
        cout<<-1<<'\n';
    }else {
        cout<<sum-res<<'\n';
    }

    return 0;
}