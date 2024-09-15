#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <queue>

using namespace std;


int result(int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    int tmp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>tmp;
            pq.push(tmp);
        }
        for(int k=0;k<n-1;k++){
            pq.pop();
        }
    }
    return pq.top();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,tmp;
    cin>>n;


    //size에서 pop되는 열 애들 pq에 집어넣고 pop. n번째는 출력하고 pop 하기
    int res=result(n);

    cout<<res;

}