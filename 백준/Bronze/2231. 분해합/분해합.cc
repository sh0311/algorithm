#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <cmath>

using namespace std;

const int CNT = 9;

int solution(int n){
    for(int i=1;i<n;i++){
        int sum=i;

        int tmp=i;
        while(tmp){
            sum+=tmp%10;
            tmp=tmp/10;
        }

        if(sum==n)
            return i;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    cout<<solution(n);


}
