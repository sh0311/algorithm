#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int k;
    cin>>k;

    int start=1;
    int end=k;
    int mid;
    int res;
    while(start<=end)
    {
        mid=(start+end)/2;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=min(mid/i,n);
        }
        if(sum<k){
           start=mid+1;
        }
        else{
            res=mid;
            end=mid-1;
        }

    }
    cout<<res;
}

