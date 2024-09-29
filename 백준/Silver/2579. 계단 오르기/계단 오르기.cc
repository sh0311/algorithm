#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solve(vector<int> &stair, int n){
    vector<int> dp(n+1, 0);
    dp[1]=stair[1];
    dp[2]=stair[1]+stair[2];

    for(int i=3;i<n+1;i++){
        dp[i]=max(dp[i-2]+stair[i], dp[i-3]+stair[i-1]+stair[i]);
    }

    return dp[n];

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> stair(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>stair[i];
    }

    int res=solve(stair,n);

    cout<<res;
}
