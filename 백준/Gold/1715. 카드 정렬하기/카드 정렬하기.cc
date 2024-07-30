#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

bool compare(pair<int, int>& a, pair<int,int>& b){
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>>pq;
    int data;

    for(int i=0;i<n;i++) {
        cin >> data;
        pq.push(data);
    }

    int data1;
    int data2;
    int sum=0;

    while(pq.size()!=1){
        data1=pq.top();
        pq.pop();
        data2=pq.top();
        pq.pop();
        sum+=data1+data2;
        pq.push(data1+data2);
    }
    cout<<sum;
}

