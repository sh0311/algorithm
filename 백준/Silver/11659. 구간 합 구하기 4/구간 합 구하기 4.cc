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



    int n,m;
    cin>>n>>m;
    int dp[100001]={};
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        dp[i]=dp[i-1]+temp;
    }

    for(int i=0;i<m;i++){
        int start,end;
        cin>>start>>end;
        cout<<dp[end]-dp[start-1]<<'\n';


    }


    return 0;
}

