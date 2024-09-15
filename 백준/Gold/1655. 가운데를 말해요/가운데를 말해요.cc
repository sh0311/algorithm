#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <queue>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp;
    cin>>n;

    priority_queue<int> max_heap;
    priority_queue<int,vector<int>, greater<int>> min_heap;


    for(int i=0;i<n;i++){
        cin>>tmp;
        if(max_heap.empty()){
            max_heap.push(tmp);

        }
        else if(max_heap.size()==min_heap.size()){
            max_heap.push(tmp);
        }
        else{
            min_heap.push(tmp);
        }
        if(!max_heap.empty()&&!min_heap.empty()&&max_heap.top()>min_heap.top()){
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        cout<<max_heap.top()<<'\n';
    }

}