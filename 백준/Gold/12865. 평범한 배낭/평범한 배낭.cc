#include <iostream>
#include <vector>

using namespace std;

int sol(int k, vector<pair<int, int>>& bas, int n) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for(int i=1;i<=n;i++) {
        for(int j=0;j<bas[i].first;j++) {
            dp[i][j]=dp[i-1][j];
        }
        for(int j=bas[i].first;j<=k;j++) {
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-bas[i].first]+bas[i].second);
        }
    }

    return dp[n][k];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<pair<int, int>> bas(n+1);

    for(int i=1;i<=n;i++) {
        int w,v;
        cin>>w>>v;
        bas[i]=(make_pair(w,v));
    }

    cout<<sol(k, bas, n);

    return 0;
}
