#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dist;
vector<vector<int>> v;

void bfs(int start) {

    deque<int> q;
    q.push_back(start);

    while(!q.empty()) {
        int val=q.front();
        q.pop_front();

        for(int i=0;i<v[val].size();i++) {
            if(dist[v[val][i]]==-1) { //방문 안함
                q.push_back(v[val][i]);
                dist[v[val][i]]=dist[val]+1;
            }
        }
    }
}

int main() {

    int n,m,k,x;
    cin>>n>>m>>k>>x;

    v.assign(n+1, vector<int>(0));
    dist.assign(n+1, -1);
    dist[x]=0;

    for(int i=0;i<m;i++) {
        int from,to;
        cin>>from>>to;
        v[from].push_back(to);
    }

    bfs(x);

    int num=0;
    for(int i=0;i<n+1;i++) {
        if(dist[i]==k) {
            cout<<i<<'\n';
            num++;
        }
    }
    if(num==0) {
        cout<<-1;
    }

    return 0;
}
