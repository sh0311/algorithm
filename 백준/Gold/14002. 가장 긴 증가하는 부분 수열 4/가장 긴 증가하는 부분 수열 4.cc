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

vector<int> dp;

int sol(vector<int>& arr, int n){
    dp.resize(n,1);
    dp[0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    return max_element(dp.begin(), dp.end())-dp.begin();
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int idx=sol(arr,n);
    cout<<dp[idx]<<'\n';
    
    vector<int> res;
    res.push_back(arr[idx]);
    int target=dp[idx]-1;
    for(int i=idx-1;i>=0;i--){
        if(dp[i]==target&& arr[i] < arr[idx]){
            res.push_back(arr[i]);
            idx=i;
            target--;
        }
        
    }
    
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }

    return 0;
}