#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<int> A(n);
    int cnt=0;

    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=n-1;i>=0;i--){
        if((k/A[i])>0){
            cnt+=k/A[i];
            k=k%A[i];
        }
    }
    cout<<cnt;




}

