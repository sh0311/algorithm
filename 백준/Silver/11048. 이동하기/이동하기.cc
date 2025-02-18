/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sol(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        dp[i][j]=max(dp[i-1][j], dp[i][j-1])+arr[i][j];
        dp[i][j]=max(dp[i][j], dp[i-1][j-1]+arr[i][j]);
    }
    
    
    return dp[n][m];
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
        cin>>arr[i][j];
    }
    
    int res=sol(arr,n,m);
    cout<<res;
    
    return 0;
}