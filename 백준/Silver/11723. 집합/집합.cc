#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <cmath>

using namespace std;
const int MAX=20;

int calculate(string order, int k){
    int num;

    if(order=="add"){
        cin>>num;
        // k의 num번째에 이미 1이 채워져있으면 그대로 두고, 0이면 1로 채우기
        k=k|1<<num;
    }
    else if(order=="remove"){
        cin>>num;
        k=k & ~(1<<num);
    }
    else if(order=="toggle"){
        cin>>num;

        if(k & (1<<num)){
            k= k&~(1<<num);
        }
        else
            k=k|(1<<num);
    }
    else if(order=="check"){
        cin>>num;
        if(k & (1<<num)){
            cout<<1<<'\n';
        }
        else
            cout<<0<<'\n';

    }
    else if(order=="all"){
        k=(1<<(MAX+1)) -1;
    }
    else if(order=="empty"){
        k=0;
    }
    return k;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m;
    cin>>m;
    string order;
    int k=0;

    for(int i=0;i<m;i++){
        cin>>order;
        k=calculate(order, k);
    }

    return 0;
}