#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int INF=2e5;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &data, int N) {
    vector<int> dist(N+1, INF);

    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int weight=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(dist[node]<weight) {
            continue;
        }
        for(int i=0;i<data[node].size();i++) {
            int len=weight+data[node][i].second;
            int nod=data[node][i].first;

            if(dist[nod]>len) {
                dist[nod]=len;
                pq.push({len, nod});
            }
        }
    }
    return dist;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, X;
    cin>>N>>M>>X;

    int start, end;
    int time;

    vector<vector<pair<int, int>>> data(N+1, vector<pair<int, int>>(0));

    for(int i=0;i<M;i++) {
        cin>>start>>end;
        cin>>time;

        data[start].push_back({end, time});
    }

    vector<int> ans(N+1,0);

    for(int i=1;i<=N;i++) {
        vector<int> res = dijkstra(i, data, N);
        if(i==X) {
            for(int j=1;j<=N;j++) {
                ans[j]+=res[j];
            }
        }
        else {
            ans[i]+=res[X];
        }
    }

    int max_val=0;
    for(int i=1;i<=N;i++) {
        max_val=max(max_val, ans[i]);
    }
    cout<<max_val;


    return 0;
}