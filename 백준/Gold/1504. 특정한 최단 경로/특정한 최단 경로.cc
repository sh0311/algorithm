#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>



using namespace std;

int INF=98765432;
vector<pair<int,int>> v[802];
int dist[803];
void bfs(int st){
    fill(dist, dist + 803, INF); // dist 배열을 INF로 초기화
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0,st));
    dist[st]=0;
    while(!q.empty()){
        int sum_distance=q.top().first;
        int x=q.top().second;
        q.pop();

        if(dist[x]<sum_distance)
            continue;
        for(int i=0;i<v[x].size();i++){
            int nx=v[x][i].first;
            int ncost=sum_distance+v[x][i].second;

            if(ncost<dist[nx]){
                q.push({ncost,nx});
                dist[nx]=ncost;
            }

        }

    }
}

int mn(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,E;
    cin>>N>>E;
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int v1,v2;
    cin>>v1>>v2;

    bfs(1);
    int to_v1=dist[v1];
    int to_v2=dist[v2];

    bfs(v1);
    int v1_to_v2=dist[v2];
    int v1_to_N=dist[N];

    bfs(v2);
    int v2_to_N=dist[N];
    //v2_to_v1이랑 v1_to_v2랑 같아서 다시 안 구함. 위에서 구한 거 이용

    int result;
    result=mn(INF,to_v1+v1_to_v2+v2_to_N);
    result=mn(result, to_v2+v1_to_v2+v1_to_N);

    if(result>=INF)
        cout<<-1;
    else
        cout<<result;

    return 0;
}

