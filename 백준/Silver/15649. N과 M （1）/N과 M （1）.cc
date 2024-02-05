#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n,m;
bool visited[10]={0,};
int arr[10]={0,};

void dfs(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=true;
            arr[depth]=i;
            dfs(depth+1);
            visited[i]=false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    dfs(0);




    return 0;
}

