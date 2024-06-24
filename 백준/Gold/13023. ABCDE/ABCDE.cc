#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

static vector<vector<int>> vec;
static vector<bool> visited;
void DFS(int num, int cnt);
static bool arrive;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    int j,k;

    arrive=false;
    vec.resize(n);
    int final=0;
    int cnt;

    visited=vector<bool>(n,false);

    for(int i=0;i<m;i++){
        cin>>j>>k;
        vec[j].push_back(k);
        vec[k].push_back(j);
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            DFS(i, 1);
            if(arrive){
                final=1;
                break;
            }
        }
    }
    cout<<final;
}

void DFS(int num, int cnt){
    if(cnt==5||arrive){
        arrive=true;
        return;
    }
    for(int v:vec[num]){
        if(!visited[v]){
            visited[v]=true;
            DFS(v, cnt+1);
        }
    }
    visited[num]=false;


}

