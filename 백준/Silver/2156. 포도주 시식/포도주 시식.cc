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

int sol(vector<int> &arr, int n){
    vector<int> dp(n+1,0);
    if (n == 1) return arr[1];
    
    dp[1]=arr[1];
    dp[2]=arr[1]+arr[2];
    
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-2]+arr[i],arr[i-1]+arr[i]+dp[i-3]);
        dp[i]=max(dp[i],dp[i-1]);
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    int res=sol(arr,n);
    cout<<res;
    
    return 0;
}