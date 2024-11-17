#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> v;
vector<int> value;
int cnt;
int N;
bool visited[100001]={false};

int sol(int q) {
    return value[q];
}

int depth(int R) {

    visited[R]=true;
    //값 있으면 그대로 값 리턴
    if(value[R]!=-1) {
        return value[R];
    }

    //방문한 적 없음
    int size=1;

    for(int i=0;i<v[R].size();i++) {
        //방문한 적 없음
        if(!visited[v[R][i]]) {
            size+=depth(v[R][i]);
        }
    }
    value[R]=size;
    return value[R];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int R,Q;
    cin>>N>>R>>Q;


    for(int i=0;i<N-1;i++) {
        int a,b;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    value.resize(N+1,-1);

    //서브트리 정점 수 계산
    depth(R);

    for(int i=0;i<Q;i++) {
        int q;
        cin>>q;
        int res=sol(q);
        cout<<res<<'\n';
    }


    return 0;
}