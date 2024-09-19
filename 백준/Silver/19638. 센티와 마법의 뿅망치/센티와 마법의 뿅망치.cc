#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <queue>
#include <cmath>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int giants;
    int myHeight;
    int max;

    int cnt=1;

    cin>>giants>>myHeight>>max;

    priority_queue<int> pq;
    int height;

    for(int i=0;i<giants;i++){
        cin>>height;
        pq.push(height);
    }

    while(cnt<=max){
        int tmp=pq.top();
        if(tmp==1 || tmp<myHeight){
            break;
        }

        pq.pop();
        pq.push(int(tmp/2));
        cnt+=1;
    }

    if(pq.top()<myHeight && cnt-1<=max){
        cout<<"YES"<<'\n'<<cnt-1;
    }

    else{
        cout<<"NO"<<'\n'<<pq.top();
    }
}