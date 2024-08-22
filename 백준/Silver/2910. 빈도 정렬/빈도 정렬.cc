#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <numeric>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

typedef pair<int,int> num;
map<int, int> order;  //index 저장

bool cmp(pair<int,int>& a, pair<int, int>& b){
    if(a.second==b.second){
        return order[a.first]<order[b.first];
    }
    return a.second>b.second;

}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,c;
    cin>>n>>c;
    int val;

    map<int, int> dic;

    for(int i=0;i<n;i++){
        cin>>val;
        dic[val]++;

        if(order[val]==0){
            order[val]=i+1;
        }
    }

    vector<num> vec(dic.begin(),dic.end());
    sort(vec.begin(), vec.end(), cmp);

    for(auto iter:vec){
        for(int i=0;i<iter.second;i++){
            cout<<iter.first<<" ";
        }
    }
}




