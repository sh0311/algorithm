#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<pair<int,int>> A(n+1);

    for(int i=1;i<n+1;i++){
        cin>>A[i].first;
        A[i].second=i;
    }

    sort(A.begin(), A.end());
    int Max=0;

    for(int i=1;i<n+1;i++){
        if(Max<A[i].second-i)
            Max=A[i].second-i;
    }
    cout<<Max+1;

    return 0;
}

