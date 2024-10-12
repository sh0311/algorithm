

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n,m;
vector<int> number;
vector<int> res;
vector<bool> isIn(10001, false);

void input(){
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(!isIn[k]){
            number.push_back(k);
            isIn[k]=true;
        }
    }
    sort(number.begin(), number.end());
}

void dfs(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<res[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<number.size();i++){
        res[cnt]=number[i];
        dfs(cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    res.resize(m);
    input();
    dfs(0);

    return 0;


}
