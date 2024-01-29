#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool sosu(int num){
    if(num<2)
        return false;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) {
            return false;
            }

    }return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int cnt=0;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(sosu(num))
            cnt+=1;
    }
    cout<<cnt<<'\n';
    return 0;
}

