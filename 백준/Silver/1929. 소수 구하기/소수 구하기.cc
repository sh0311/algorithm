#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m,n;
    cin>>m>>n;

    vector<int> arr(n+1);
    for(int i=2;i<=n;i++){
        arr[i]=i;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(arr[i]==0)
            continue;
        for(int j=i+i;j<=n;j=j+i){
                arr[j]=0;
        }
    }
    for(int i=m;i<=n;i++){
        if(arr[i]!=0)
            cout<<arr[i]<<"\n";
    }
}




