#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long can(vector<long long>& arr,long long length,int target){
    long long cnt=0;
    for(long long ar:arr){
        cnt+=ar/length;
    }
    if(cnt>=target)
        return true;
    return false;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    int K;
    cin>>K;
    vector<long long> arr(N);

    long long max_len=0;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    long long start=1;
    long long end=*max_element(arr.begin(),arr.end());

    while(start<=end){
        long long mid=start+(end-start)/2;


        if(can(arr, mid, K)){
            max_len=mid;
            start=mid+1;
        }
        else
            end=mid-1;

    }
    cout<<max_len;



    return 0;
}

