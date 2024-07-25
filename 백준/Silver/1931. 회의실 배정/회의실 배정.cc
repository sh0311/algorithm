#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

bool compare(pair<int, int>& a, pair<int,int>& b){
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector <pair<int, int>> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i].first;
        cin>>A[i].second;
    }

    sort(A.begin(), A.end(), compare);
    int end=0;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(A[i].first>=end){
            cnt+=1;
            end=A[i].second;
        }
    }
    cout<<cnt;
}

