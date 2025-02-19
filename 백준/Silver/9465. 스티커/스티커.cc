/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int sol(vector<vector<int>>& arr, int n){
    vector<vector<int>> dp(2,vector<int>(100000,-1));
    
    dp[0][0]=arr[0][0];
    dp[1][0]=arr[1][0];
    dp[0][1]=dp[1][0]+arr[0][1];
    dp[1][1]=dp[0][0]+arr[1][1];
    
    if(n==1){
        return max(dp[1][0], dp[0][0]);
    }
  
        for(int j=2;j<n;j++){
                dp[0][j]=max(dp[1][j-1],dp[1][j-2])+arr[0][j];
            
                dp[1][j]=max(dp[0][j-1],dp[0][j-2])+arr[1][j];
            
        }
        
    return max(dp[1][n-1], dp[0][n-1]);
}

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        
        vector<vector<int>> arr(2,vector<int>(n));
        
        for(int j=0;j<2;j++)
            for(int k=0;k<n;k++){
                cin>>arr[j][k];
            }
        int res=sol(arr,n);
        cout<<res<<'\n';
    }
    
    return 0;
}