#include <iostream>
#include<vector>
using namespace std;

int dp(vector<vector<int>> &board, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1,0)); //i=0,j=0인 지점은 i-1, j-1이 음수가 되어 연산 불가능하므로 패딩해주고 원래 i=0, j=0인 곳을 i=1, j=1로 관찰
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(board[i-1][j-1]==1){
                // 한번에 세개이상의 값에서 min 사용불가. 두개씩 쪼개야 함
                dp[i][j]=min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1])+1;
                }
            ans=max(ans, dp[i][j]);
            }
    } 
    return ans;
        
    
}


int solution(vector<vector<int>> board)
{
    int n=board.size();
    int m=board[0].size();
    int res=dp(board, n, m);
    return res*res;
}