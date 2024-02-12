#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;




int knapsack(int N,int K,vector<int>& W,vector<int>& v){
    vector<vector<int>> dp(N+1,vector<int>(K+1,0));
    for(int i=1;i<=N;i++)
        for(int w=1;w<=K;w++){
            if (w-W[i-1]>=0){
                dp[i][w]=max(dp[i-1][w],dp[i-1][w-W[i-1]]+v[i-1]);
            }
            else
                dp[i][w]=dp[i-1][w];
        }
    return dp[N][K];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin>>N>>K;
    vector<int> w(N),v(N);


    for(int i=0;i<N;i++)
        cin>>w[i]>>v[i];

    cout<<knapsack(N,K,w,v)<<'\n';







    return 0;
}

