#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int res=-1;

void dfs(vector<vector<int>>& family, vector<bool>& visited, int now, int target2, int cnt){
    visited[now]=true;
    if(target2==now){
        res=cnt;
    }
    for(int i=0;i<family[now].size();i++){
        if(!visited[family[now][i]]){
            dfs(family, visited, family[now][i],target2, cnt+1);
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

   int n;
   cin>>n;

   int target1, target2;
   cin>>target1>>target2;

   int num;
   cin>>num;
   vector<vector<int>> family(n+1);
   for(int i=0;i<num;i++){
       int first, second;
       cin>>first>>second;
       family[first].push_back(second);
       family[second].push_back(first);
   }
   int cnt=0;
   vector<bool> visited(n+1, false);
   dfs(family, visited, target1, target2, cnt);
    cout<<res;

}
