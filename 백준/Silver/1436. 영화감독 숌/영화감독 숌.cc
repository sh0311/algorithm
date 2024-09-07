#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <cmath>

using namespace std;

int isSix(string value, int cnt){
    if(value.find("666")!=-1){
        cnt+=1;
    }
    return cnt;
}
int main(){
    int n, value;
    cin>>n;

    int cnt=0;

    for(value=666;;value++){
        string val=to_string(value);
        cnt=isSix(val,cnt);
        if(cnt==n){
            cout<<val;
            break;
        }
    }
}