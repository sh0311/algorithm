#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

//10^3=1000~2^10=1024
//10^18 ~2^60
const int MAX =60;


pair<int, int> getPair(ll m){
    int x,y;

    // m이 2의 제곱수
    for(ll i=0;i<MAX;i++){
        if(m==(ll)1<<i){
            return {i-1,i-1};
        }
    }

    // m이 2의 제곱수가 아님
    for(x=0;x<MAX;x++){
        if(m&(ll)1<<x){
            m-=(ll)1<<x;
            break;
        }
    }
    for(y=0;y<MAX;y++){
        if(m&(ll)1<<y){
            break;
        }
    }
    return {x,y};

}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll m;
    cin>>n;
    while(n--){
        cin>>m;
        pair<int, int> ans=getPair(m);
        cout<<ans.first<<" "<<ans.second<<'\n';
    }

}




