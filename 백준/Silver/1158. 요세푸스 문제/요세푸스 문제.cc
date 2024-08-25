#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

vector<int> cal(queue<int>& que, vector<int>& vec, int k){
    while(que.size()>1){
        for(int i=0;i<k-1;i++){
            que.push(que.front());
            que.pop();
        }
        vec.push_back(que.front());
        que.pop();
    }
    vec.push_back(que.front());
    que.pop();
    return vec;
}

void output(vector<int>& vec){
    cout<<"<";
    for(int i=0;i<vec.size();i++){
        if(i==0){
            cout<<vec[i];
        }
        else
            cout<<", "<<vec[i];
    }
    cout<<">";
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    queue<int> que;
    for(int i=0;i<n;i++){
        que.push(i+1);
    }

    vector<int> vec;

    vec=cal(que, vec,k);

    output(vec);

}




