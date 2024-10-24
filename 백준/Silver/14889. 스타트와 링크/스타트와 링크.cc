#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int cnt;
int n;
int min_val=99;
vector<int> tmp;


void task() {
    int tmp1_sum=0, tmp2_sum=0;

    vector<int> tmp2;
    //나머지 팀
    for(int i=0;i<n;i++) {
        if(!visited[i])
            tmp2.push_back(i);
    }

    for(int i=0;i<tmp.size();i++) {
        for(int j=i+1;j<tmp.size();j++) {
            tmp1_sum+=graph[tmp[i]][tmp[j]]+graph[tmp[j]][tmp[i]];
        }
    }
    for(int i=0;i<tmp2.size();i++) {
        for(int j=i+1;j<tmp2.size();j++) {
            tmp2_sum+=graph[tmp2[i]][tmp2[j]]+graph[tmp2[j]][tmp2[i]];
        }
    }

    min_val=min(min_val,abs(tmp1_sum-tmp2_sum));

}
void dfs(int start, int cnt) {
    if(cnt==n/2) {
        task();
        return;
    }
    for(int i=start;i<n;i++) {
        if(visited[i])
            continue;
        visited[i]=true;
        tmp.push_back(i);
        dfs(i+1,cnt+1);
        visited[i]=false;
        tmp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    graph.resize(n, vector<int>(n));
    visited.resize(n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            int val;
            cin>>val;
            graph[i][j]=val;
        }


    dfs(0,0);

    cout<<min_val;
}
