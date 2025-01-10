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


int dynamic(int n, vector<vector<int>> &arr){
    
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for(int i=1;i<n+1;i++){
        for(int j=0;j<2;j++){
            if(i>n+1-arr[i][0]){
                arr[i][1]=0;
            }
            dp[i][j]=arr[i][j];
        }
    }
    
    for(int i=2;i<n+1;i++){
        for(int k=1;k<i;k++){
            if(dp[k][0]<=i-k){
                dp[i][1]=max(dp[i][1], dp[k][1]+arr[i][1]);
            }
        }
    }

    int res=dp[1][1];
    for(int i=2;i<n+1;i++){
        res=max(res,dp[i][1]);
    }
    
    return res;
}


int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> arr(n+1,vector<int>(2));
    
    for(int i=1;i<=n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    
    int res=dynamic(n,arr);

    cout<<res;
    
    return 0;
}