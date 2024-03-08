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

    int start=1;
    int end=1;

    int n;
    cin>>n;

    int cnt=0;
    int sum=0;

    while(end<=n+1 && start<=end){
    if(sum>n){
        sum-=start;
        start+=1;

    }
    else if(sum<n){
        sum+=end;
        end+=1;
    }
    else{
        cnt+=1;
        sum+=end;
        end+=1;

    }}
    cout<<cnt;
    return 0;
}
