#include <iostream>
#include <map>
#include <vector>

using namespace std;

int overtake(int n, vector<int>& order_out){
    int overtake=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(order_out[i]>order_out[j]){
                overtake++;
                break;
            }
        }
    }
    return overtake;
}

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string car;
    map<string, int> order_in;
    vector<int> order_out;

    for(int i=1;i<=n;i++){
        cin>>car;
        order_in[car]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>car;
        order_out.push_back(order_in[car]);
    }
    cout<<overtake(n,order_out);



}

