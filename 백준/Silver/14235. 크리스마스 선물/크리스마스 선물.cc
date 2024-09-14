#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, place, value;
    cin>>n;

    priority_queue<int> pq;

    while(n--){
        cin>>place;
        if(place==0){
            if(pq.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else{
            while(place--){
                cin>>value;
                pq.push(value);
            }
        }
    }
}