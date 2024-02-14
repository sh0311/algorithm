#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int lowerbound(vector<int>& A, int target){
    int start=0;
    int end=A.size();

    while(start<end){
        int mid=(start+end)/2;
        if(target<=A[mid]) {
            end=mid;
        }
        else
            start=mid+1;
    }
    return start;
}
int upperbound(vector<int>& A, int target){
    int start=0;
    int end=A.size();

    while(start<end){
        int mid=(start+end)/2;
        if(target>=A[mid]) {
            start=mid+1;
        }
        else
            end=mid;

    }
return start;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<int> arr(N);

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int q;
        cin>>q;
        int num=lowerbound(arr,q);
        int num2= upperbound(arr, q);

        cout<<num2-num<<" ";
    }


    return 0;
}

